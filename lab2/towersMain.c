#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;

    if (argc == 2)
    {
	n = atoi(argv[1]);
	if (n <= 0)
	{
		fprintf(stderr,"Invalid input, arguments are in an invalid format. \n");
        	exit(0);
	}
    }

    else if (argc >= 3) 
    {
        n = atoi(argv[1]);
	from = atoi(argv[2]);
	dest = atoi(argv[3]);

	if (n <= 0|| from <= 0 || dest <= 0)
    	{
		fprintf(stderr,"Invalid input, arguments are in an invalid format. \n");
        	exit(0);
        }

	else if (from == dest || from > 3 || dest > 3)
	{
		fprintf(stderr,"Incorrect Input, arguments are in an invalid format. \n");
		exit(0);
	}
    }
    towers(n, from, dest);
    exit(0);
}
