#include <stdio.h>
#include <stdlib.h>

#include "encode.h"
#include "io.h"
#include "parity.h"

extern int 
encode(int argc, char * argv[])
{
    // TODO
    int charles[MAXARRAYLENGTH];
    int leftNibbleParity[MAXARRAYLENGTH];
    int rightNibbleParity[MAXARRAYLENGTH];
    int testingPurposes[MAXNIBBLE];
	int i;
	for (i=0; i<MAXARRAYLENGTH; i++)
	{
		charles[i] = 0;
		
	}
	readFile(argv[1], charles);
	int k=0;
	for (i=0; i<MAXARRAYLENGTH;i++)
	{
		leftNibbleParity[i] = LeftNibbleParity(charles[i]); 
		rightNibbleParity[i] = RightNibbleParity(charles[i]); 
		testingPurposes[k] = leftNibbleParity[i];
		k++;
		testingPurposes[k] = rightNibbleParity[i]; 
		k++;
	}
	
	writeFile(argv[2], testingPurposes);
	
	
	
	
	
    return (0);
}
