#include <stdio.h>
#include <ctype.h>      // for isupper() etc.
#include <sys/socket.h> // for send() and recv()
#include <unistd.h>     // for sleep(), close()
#include <string.h>
#include <stdlib.h>
#include <libusb-1.0/libusb.h>
#include "Auxiliary.h"
#include "HandleTCPClient.h"
#include "Xpad.h"

#define RCVBUFSIZE 32   /* Size of receive buffer */

void HandleTCPClient (int clntSocket)
{ 
    // 'clntSocket' is obtained from AcceptTCPConnection()
	libusb_device_handle *h;
    char echoBuffer[RCVBUFSIZE];        /* Buffer for received */
    int  recvMsgSize;                   /* Size of received message */
	int echoStringLen;  
	char echoString[RCVBUFSIZE]; 		/* Buffer for received string */
	int flag=5;
    /* Receive message from client */
    recvMsgSize = recv (clntSocket, echoBuffer, RCVBUFSIZE, 0);
    if (recvMsgSize < 0)
    {
        DieWithError ("recv() failed");
    }
    info_d ("Recv", recvMsgSize);
    libusb_init(NULL);
    h = libusb_open_device_with_vid_pid(NULL, 0x45e, 0x28e);
	if (h == NULL) 
	{
		fprintf(stderr, "Failed to open device\n");
	}
    
     while(flag != 0)
    {
		printf("Received: %s \n", echoBuffer);
		flag = atoi(echoBuffer);
		printf("Flag = %d\n", flag);
		if (flag == 1)
		{
			if (turnLedOn(h) == 0)
			{
				strcpy(echoString, "LedsTurnedOn");
				echoStringLen = strlen (echoString); 
				delaying();
				send(clntSocket, echoString, echoStringLen+1, 0);
				info_s("Transmited", echoString);
			}
			else
			{
				strcpy(echoString ,"ErrorOccured");
				echoStringLen = strlen (echoString); 
				delaying();
				send(clntSocket, echoString, echoStringLen+1, 0);
				info_s("Transmited", echoString);
			}
			//flag = 0;
		}
		
		else if (flag == 2)
		{
			if (rumbleXpad(h) == 0)
			{
				strcpy(echoString, "XpadIsRumbling");
				echoStringLen = strlen (echoString); 
				delaying();
				send(clntSocket, echoString, echoStringLen+1, 0);
				info_s("Transmited", echoString);
			}
			else
			{
				strcpy(echoString, "ErrorOccured");
				echoStringLen = strlen (echoString); 
				delaying();
				send(clntSocket, echoString, echoStringLen+1, 0);
				info_s("Transmited", echoString);
			}
			//flag = 0;
		}
		
		else if (flag == 3)
		{
			if (turnLedOff(h) == 0)
			{
				strcpy(echoString, "LedsTurnedOff");
				echoStringLen = strlen (echoString); 
				delaying();
				send(clntSocket, echoString, echoStringLen+1, 0);
				info_s("Transmited", echoString);
			}
			else
			{
				strcpy(echoString ,"ErrorOccured");
				echoStringLen = strlen (echoString); 
				delaying();
				send(clntSocket, echoString, echoStringLen+1, 0);
				info_s("Transmited", echoString);
			}
			//flag = 0;
		}
		
		else if (flag == 4) 
		{
			if (rumbleXpadOff(h) == 0)
			{
				strcpy(echoString, "XpadRumblingOff");
				echoStringLen = strlen (echoString); 
				delaying();
				send(clntSocket, echoString, echoStringLen+1, 0);
				info_s("Transmited", echoString);
			}
			else
			{
				strcpy(echoString, "ErrorOccured");
				echoStringLen = strlen (echoString); 
				delaying();
				send(clntSocket, echoString, echoStringLen+1, 0);
				info_s("Transmited", echoString);
			}
			//flag = 0;
		}
		
		else if ((flag < 0) || (flag > 5))
		{
			strcpy(echoString, "Invalid option");
			echoStringLen = strlen (echoString); 
			delaying();
			send(clntSocket, echoString, echoStringLen+1, 0);
			info_s("Transmited", echoString);
		}
		
		else if (flag == 0)
		{
			strcpy(echoString, "Closed");
				echoStringLen = strlen (echoString); 
				delaying();
				send(clntSocket, echoString, echoStringLen+1, 0);
		}
		/*
		else if (flag == 5)
		{
			if (buttonStatus(h,status) == 0)
			{
				strcpy(echoString, status);
				echoStringLen = strlen (echoString); 
				delaying();
				send(clntSocket, echoString, echoStringLen+1, 0);
				info_s("Transmited", echoString);
			}
			else
			{
				strcpy(echoString, "ErrorOccured");
				echoStringLen = strlen (echoString); 
				delaying();
				send(clntSocket, echoString, echoStringLen+1, 0);
				info_s("Transmited", echoString);
			}
			flag = 0;
		} */
		
		
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
