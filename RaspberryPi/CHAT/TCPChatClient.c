#include <stdio.h>
#include <string.h>     // for strlen()
#include <stdlib.h>     // for exit()
#include <sys/socket.h> // for send() and recv()
#include <unistd.h>     // for sleep(), close()
#include <semaphore.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include "Auxiliary.h"
#include "CreateTCPClientSocket.h"
 
#define RCVBUFSIZE 32   /* Size of receive buffer */

int main (int argc, char *argv[])
{
    int         sock;                   /* Socket descriptor */
    char        echoString[RCVBUFSIZE]; /* String to send to echo server */
    char        echoBuffer[RCVBUFSIZE]; /* Buffer for received string */
    int         echoStringLen;          /* Length of string to echo */
   // int         bytesRcvd;              /* Bytes read in single recv() */
	sem_t *     sem_A = SEM_FAILED;
	int flag = 1;
    parse_args (argc, argv);
    sock = CreateTCPClientSocket (argv_ip, argv_port);
    sem_A = sem_open ("A", O_CREAT ,0777, 1);
    printf("Please wait for other processes to finish their job \n");
	sem_wait(sem_A);
	while(flag != 0)
    {
        printf("Please enter your data \nType 0 to exit \n");
		fgets  (echoString, sizeof (echoString), stdin);
		flag = atoi(echoString);
		echoStringLen = strlen (echoString);
		delaying();
		send(sock, echoString, echoStringLen+1, 0);
		info_s("Transmited", echoString);
		//bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE, 0);
		recv(sock, echoBuffer, RCVBUFSIZE, 0);
		printf("Received: %s \n", echoBuffer);
		//printf("Bytes Rcv %d \n", bytesRcvd);
		printf("Flag = %d \n", flag);
		delaying ();
    }
    sem_post(sem_A);
    
	

    close (sock);
    info ("close & exit");
    exit (0);
}
