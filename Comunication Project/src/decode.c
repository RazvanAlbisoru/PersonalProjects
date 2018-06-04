#include <stdio.h>
#include <stdlib.h>

#include "decode.h"
#include "io.h"
#include "parity.h"

extern int
decode (int argc, char * argv[])
{
    int everythingDone[MAXARRAYLENGTH];
    int charles[MAXNIBBLE];
    int leftNibbleParity[MAXARRAYLENGTH];
    int rightNibbleParity[MAXARRAYLENGTH];
    int i;
    for (i=0; i<MAXARRAYLENGTH; i++)
	{
		charles[i] = 0;
		
	}
	readFile(argv[1], charles);
	int j=0;
    for (i=0; i<MAXARRAYLENGTH;i++)
	{
		leftNibbleParity[i] = Check(charles[j]);
		j++; 
		rightNibbleParity[i] = Check(charles[j]); 
		j++;
		everythingDone[i] = MergeBothParity(RemoveLeftParity(leftNibbleParity[i]), RemoveRightParity(rightNibbleParity[i]));
	}
	
	writeFile(argv[2], everythingDone);
    return (0);
}
