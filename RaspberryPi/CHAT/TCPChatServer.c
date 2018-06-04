#include <stdio.h>
#include <string.h>     // for strlen()
#include <stdlib.h>     // for exit()
#include <sys/socket.h> // for send() and recv()
#include <unistd.h>     // for sleep(), close()
#include "Auxiliary.h"
#include "AcceptTCPConnection.h"
#include "CreateTCPServerSocket.h"
#include "HandleTCPClient.h"
 
int main (int argc, char * argv[])
{
    int servSock;                    /* Socket descriptor for server */
    int clntSock;                    /* Socket descriptor for client */

    parse_args (argc, argv);
    
    servSock = CreateTCPServerSocket (argv_port);

    for (;;) /* Run forever */
    {
        clntSock = AcceptTCPConnection (servSock);
        HandleTCPClient (clntSock);
    }
    /* NOT REACHED */
}
