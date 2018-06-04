#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Xpad.h"

int turnLedOn(libusb_device_handle *h)
{
	unsigned char data[] = { 0x01, 0x03, 0x0A};
	int error;
	int transferred;
	libusb_init(NULL);
	error = libusb_interrupt_transfer(h, 0x01, data, sizeof data, &transferred, 0);
		if (error != 0) 
		{
		fprintf(stderr, "Transfer failed: %d\n", error);
		return (2);
		}
	return(0);
}

int turnLedOff(libusb_device_handle *h)
{
	unsigned char data[] = { 0x01, 0x03, 0x00};
	int error;
	int transferred;
	libusb_init(NULL);
	error = libusb_interrupt_transfer(h, 0x01, data, sizeof data, &transferred, 0);
		if (error != 0) 
		{
		fprintf(stderr, "Transfer failed: %d\n", error);
		return (2);
		}
	return(0);
}

int rumbleXpad(libusb_device_handle *h)
{
	unsigned char data2[] = { 00,0x08,00,0xFF,0x02,00,00,00 };
	int error;
	int transferred;
	libusb_init(NULL);
	error = libusb_interrupt_transfer(h, 0x01, data2, sizeof data2, &transferred, 0);
	printf("2nd one: %d \n", transferred);
	if (error != 0) 
	{
		fprintf(stderr, "Transfer 2nd failed: %d\n", error);
		return (2);
	}
	return(0);
}

int rumbleXpadOff(libusb_device_handle *h)
{
	unsigned char data2[] = { 00,0x08,00,0x00,0x00,00,00,00 };
	int error;
	int transferred;
	libusb_init(NULL);
	error = libusb_interrupt_transfer(h, 0x01, data2, sizeof data2, &transferred, 0);
	printf("2nd one: %d \n", transferred);
	if (error != 0) 
	{
		fprintf(stderr, "Transfer 2nd failed: %d\n", error);
		return (2);
	}
	return(0);
}
/*
int buttonStatus(libusb_device_handle *h, char *status)
{
	
	unsigned char data[32] = {};
	unsigned char previousData[32] = {};
	int newButtonPressed = 0;
	//int16_t j = 0;
	int error, transferred;
	int z;
	int i;
	libusb_init(NULL);
	
	if ((error = libusb_interrupt_transfer(h, 0x81, data, sizeof(data), &transferred, 0)) != 0) 
		{
			fprintf(stderr, "Transfer failed: %d\n", error);
			return (1);
		}
	
		for(z = 0; z < transferred; z++)
		{
			if(z < 2 || z > 5)
			{
				data[z] = 0x0;
			}
		}
		
			
		for(i = 0; i < transferred; i++)
		{						
			if(data[i] != previousData[i])
			{
				newButtonPressed = 1;
				if(i == 2)
				{
					if((data[i] & 0x01) == 0x01)
					{
						*status=*status + "U";
					}
					if((data[i] & 0x02) == 0x02)
					{
						*status=*status + " D";
					}
					if((data[i] & 0x04) == 0x04)
					{
						*status=*status + " L";
					}
					if((data[i] & 0x08) == 0x08)
					{
						*status=*status + " R";
					}
					if((data[i] & 0x10) == 0x10)
					{
						*status=*status + " Back";
					}
					if((data[i] & 0x20) == 0x20)
					{
						*status=*status + " Start";
					}
				}
				if(i == 3)
				{
					if((data[i] & 0x02) == 0x02)
					{
						*status=*status + " RB";
					}
					if((data[i] & 0x03) == 0x03)
					{
						*status=*status + " LB";
					}
					if((data[i] & 0x04) == 0x04)
					{
						*status=*status + " HOME";
					}
					if((data[i] & 0x10) == 0x10)
					{
						*status=*status + " A";
					}
					if((data[i] & 0x20) == 0x20)
					{
						*status=*status + " B";
					}
					if((data[i] & 0x40) == 0x40)
					{
						*status=*status + " X";
					}
					if((data[i] & 0x80) == 0x80)
					{
						*status=*status + " Y";
					}
				}
				if(i == 4)
				{
					if((data[i] & 0xFF) >= 0x01)
					{
						*status=*status + " LT";
					}
				}
				if(i == 5)
				{
					if((data[i] & 0xFF) >= 0x01)
					{
						*status=*status + " RT";
					}
				}	
			}
			previousData[i] = data[i];
		}
		if(newButtonPressed == 1)
		{
			newButtonPressed = 0;
		}
	
		
	return(0);
} */
