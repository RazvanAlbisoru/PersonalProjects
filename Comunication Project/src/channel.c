#include <stdio.h>
#include <stdlib.h>		// for srand()
#include <time.h>		// for time()

#include "channel.h"
#include "io.h"
#include "noise.h"

extern int 
channel(int argc, char * argv[])
{
	srand (time (NULL));	// take the current time as seed for random generator
	
    // TODO
    int rValue[MAXARRAYLENGTH];
    int r = rand() % 7;
    int finalValues[MAXARRAYLENGTH];
    int i;
    for (i=0;i<MAXARRAYLENGTH;i++)
    {
		rValue[i] = 0;
		finalValues[i] = 0;
	}
    readFile(argv[1], rValue);
    for (i=0;i<MAXARRAYLENGTH;i++)
    {
		finalValues[i] = rValue[i];
		if (i%2 != 0)
		finalValues[i] = createNewValue(rValue[i], r);
	}
	
    
    writeFile(argv[2], finalValues);
    
    return (0);
}
