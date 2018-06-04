#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../../ResourceDetector/resource_detector.h"
#include "io.h"




// use your own functions.
void readFile(char *fileName, int* charles)
{
	FILE* fp;
	fp = fopen(fileName, "rb");
	int counter = 0;
	int c;
	if (fp == NULL)
	{
		printf("Error while opening file \n");
		
	}
	
	while((c = fgetc(fp)) != EOF)
	{
        charles[counter] = (char) c;
        counter++;
    }
    fclose(fp);
}

void writeFile(char *fileName, int* charles)
{
	FILE* fp;
	fp = fopen(fileName, "w");
	if (fp == NULL)
	{
		printf("Error while opening file to write \n");
	}
	int i;
	for (i = 0; i<MAXARRAYLENGTH; i++)
	{
		fputc(charles[i], fp);
	}
	fclose(fp);
	
}




