#include <stdio.h>
#include "noise.h"

void changeBitValue(int* value)
{
	if (*value == 1)
	*value = 0;
	else if (*value == 0)
	*value = 1;
} 

int createNewValue(int value, int r)
{
	int bits[7];
	int temp = value;
	int i;
	for (i=0;i<7;i++)
	{
		if ((temp&1) == 1)
		{
			bits[i] = 1;
		}
		else
		{
			bits[i] = 0;
		}
		temp = temp >> 1;
	}
	
	changeBitValue(&bits[r]); // Flip a random bit
	
	int VAC = 0; //VAC = ValueAfterChangeOfBits.
	if (bits[0] == 1)
	{
		VAC = VAC + 1;
	}
	
	for(i=1;i<7;i++)
	{
		if (bits[i] == 1)
		{
			VAC = VAC + (2<<(i-1));
		}
	}
	return VAC;
	
	
}
