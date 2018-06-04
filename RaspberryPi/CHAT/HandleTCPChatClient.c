#include <stdio.h>
#include <ctype.h>      // for isupper() etc.
#include <sys/socket.h> // for send() and recv()
#include <unistd.h>     // for sleep(), close()
#include <string.h>

#include "Auxiliary.h"
#include "HandleTCPClient.h"

#define RCVBUFSIZE 32   /* Size of receive buffer */

void HandleTCPClient (int clntSocket)
{
    // 'clntSocket' is obtained from AcceptTCPConnection()

    char echoBuffer[RCVBUFSIZE];        /* Buffer for echo string */
    int  recvMsgSize;                   /* Size of received message */
	int echoStringLen;
	char        echoString[RCVBUFSIZE]; /* Buffer for received string */
    /* Receive message from client */
    recvMsgSize = recv (clntSocket, echoBuffer, RCVBUFSIZE+1, 0);
    if (recvMsgSize < 0)
    {
        DieWithError ("recv() failed");
    }
    info_d ("Recv", recvMsgSize);
    
     while(((strncmp(echoBuffer, "quit", 4)) != 0))
    {
		printf("Received: %s \n", echoBuffer);
        printf("Please enter your data \n");
		fgets (echoString, sizeof (echoString), stdin);
	//	printf("%s \n", echoString);
		echoStringLen = strlen (echoString); /* Determine input length */
	//	printf("%d", echoStringLen);
		delaying();
		send(clntSocket, echoString, echoStringLen+1, 0);
		info_s("Transmited", echoString);
        recvMsgSize = recv (clntSocket, echoBuffer, RCVBUFSIZE+1, 0);
        if (recvMsgSize < 0)
        {
            DieWithError ("recv() failed");
        }
        info_d ("recv", recvMsgSize);
    }

    close (clntSocket);    /* Close client socket */
    info ("close");
}
