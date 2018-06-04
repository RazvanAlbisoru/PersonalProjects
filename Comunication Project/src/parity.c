#include <stdio.h>
#include "parity.h"
/*
int main()
{
	//printf("RemoveLeftParity(65) %d \n", RemoveLeftParity(LeftNibbleParity(65)));
	//printf("RemoveLeftParity(65) %d \n", RemoveRightParity(RightNibbleParity(65)));
	
} */
int Check(int value)
{
	int VAC = 0;
	int d[4];
	int p[3];
	int flag[3];
	int cuc[7];
	int temp = value;
	int i;
	for (i=0;i<3;i++)
	{
		flag[i] = 0;
		p[i]=0;
	}
	
	for (i=0;i<7;i++)
	cuc[i] = 0;
	for (i=0;i<4;i++)
	d[i]=0;
	int j=0;
	for (i=0;i<7;i++)
	{
		if ((temp & 1) == 1)
		{
			if (i<3)
			{
				p[i] = 1;
			}
			else
			{
				d[j] = 1;
				j++;
			}
		}
		else
		{
			if (i<3)
			{
				p[i] = 0;
			}
			else
			{
				d[j] = 0;
				j++;
			}
		}
		temp = temp >> 1;
	}
	if ((d[0] + d[1] + d[2] + p[0]) %2 != 0)
	flag[0] = 1;
	if ((d[0] + d[1] + d[3] + p[1]) %2 != 0)
	flag[1] = 1;
	if ((d[1] + d[2] + d[3] + p[2]) %2 != 0)
	flag[2] = 1;
	
	if ((flag[0] == 1) && (flag[1] == 1) && (flag[2] == 1))
	{
		if (d[1] == 1)
		d[1] = 0;
		else 
		d[1] = 1;
	}
	
	if ((flag[0] == 1) && (flag[1] == 1))
	{
		if (d[0] == 1)
		d[0] = 0;
		else
		d[0] = 1;
	}
	
	if ((flag[0] == 1) && (flag[2] == 1))
	{
		if (d[2] == 1)
		d[2] = 0;
		else
		d[2] = 1;
	}
	
	if ((flag[1] == 1) && (flag[2] == 1))
	{
		if (d[3] == 1)
		d[3] = 0;
		else
		d[3] = 1;
	}
	
	j=0;
	for (i=0;i<7;i++)
	{
		if (i<3)
		{
			cuc[i] = p[i];
		}
		else
		{
			cuc[i] = d[j];
			j++;
		}
	}
	
	if (cuc[0] == 1)
	VAC = VAC + 1;
	
	for (i=1;i<7;i++)
	{
		if (cuc[i] == 1)
		VAC = VAC + (2 << (i-1));
	}
	
	return VAC;
	
}
int RemoveLeftParity(int value)
{
	value = value >> 3;
	value = value << 4;
	return value;
}

int RemoveRightParity(int value)
{
	value = value >> 3;
	return value;
}

int MergeBothParity(int valueLeft, int valueRight)
{
	int value;
	value = valueLeft + valueRight;
	return value;
}

int RightNibbleParity(int value)
{
	int p0,p1,p2;
	int bits[4];
	value = value & 15;
	int temp = value;
	int i;
	for (i=0;i<4;i++)
	{
		if ((temp & 1) == 1)
		{
			bits[i] = 1;
		}
		else
		{
			bits[i] = 0;
		}
		temp = temp >> 1;
		
	}
	if ((bits[0] + bits[1] + bits[2]) %2 == 0)
	{
		p0 = 0;
	}
	else
	{
		p0 = 1;
	}
	if ((bits[0] + bits[1] + bits[3]) %2 == 0)
	{
		p1 = 0;
	}
	else
	{
		p1 = 2;
	}
	if ((bits[1] + bits[2] + bits[3]) %2 == 0)
	{
		p2 = 0;
	}
	else
	{
		p2 = 4;
	}
	value = value << 3;
	value = value + p0 + p1+p2;
	return value;
}
int LeftNibbleParity(int value)
{
	int p0,p1,p2;
	int bits[4];
	value = value >> 4;
	int temp = value;
	int i;
	for (i=0;i<4;i++)
	{
		if ((temp & 1) == 1)
		{
			bits[i] = 1;
		}
		else
		{
			bits[i] = 0;
		}
		temp = temp >> 1;
	}
	if ((bits[0] + bits[1] + bits[2]) %2 == 0)
	{
		p0 = 0;
	}
	else
	{
		p0 = 1;
	}
	if ((bits[0] + bits[1] + bits[3]) %2 == 0)
	{
		p1 = 0;
	}
	else
	{
		p1 = 2;
	}
	if ((bits[1] + bits[2] + bits[3]) %2 == 0)
	{
		p2 = 0;
	}
	else
	{
		p2 = 4;
	}
	value = value << 3;
	value = value + p0 + p1+p2;
	return value;
}
