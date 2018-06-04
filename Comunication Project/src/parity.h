#ifndef _PARITY_H
#define _PARITY_H
#define MAXNIBBLE 101

int RightNibbleParity(int value);
int LeftNibbleParity(int value);
int RemoveRightParity(int value);
int RemoveLeftParity(int value);
int MergeBothParity(int valueLeft, int valueRight);
int Check(int value);

#endif
