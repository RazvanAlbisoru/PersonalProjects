#ifndef _X_PAD_H_
#define _X_PAD_H_

int turnLedOn(libusb_device_handle *h);
int rumbleXpad(libusb_device_handle *h);
//int buttonStatus(libusb_device_handle *h, char *status);
int turnLedOff(libusb_device_handle *h);
int rumbleXpadOff(libusb_device_handle *h);


#endif
