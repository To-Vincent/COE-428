#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int main(int argc, char * argv[])
{
int data[100000];
int nDataItems;
int i;

    	if (argc > 1) 
	{
       		fprintf(stderr, "The command line arguments are:\n");
        	for(i = 1; i < argc; i++) 
		{
		nDataItems = i;

		data[i-1] = atoi(argv[i]);
        	}
    	} 
	else 
	{
       		fprintf(stderr, "There were no command line arguments.\n");
		nDataItems = 4;
		data[0] = 80;
		data[1] = 60;
		data[2] = 70;
		data[3] = 90;
    	}

mySort(data,nDataItems);

for (i = 0; i < nDataItems - 1; i++)
{
	if (data[i] > data[i+1])
	{
		fprintf(stderr, "Sort error: data[%d] (= %d)"
		" should be <= data[%d] (=%d) - -aborting\n",
		i, data[i], i+1, data[i+1]);
	exit(1);
	}
}

for (i = 0; i < nDataItems; i++)
{
	printf("%d\n", data[i]);
}
exit(0);
}
