#include "mySort.h"
#include "metrics.h"

void merge(int array[], int a, int b, int c, int d)
{
	int e;
	int f;
	int g = 0;
	int mergeArray[MAX_SIZE_N_TO_SORT]; 

	e = a;
	f = b;

	while(f <= d && e <= b)
	{
		if(myCompare(array[e],array[f]) < 0)
		{
			mergeArray[g] = array[e];
			e++;
		}

		else
		{
			mergeArray[g] = array[f];
			f++;
		}
		g++;		
        }

	for(g = 0; e <= d;e++, g++)
	{
		mySwap(&array[e],&mergeArray[g]);
	}

	while(f <= d)
	{
		myCopy(&array[f],&mergeArray[g]);
		f++;
		g++;
	}

	while(e <= b)
	{
		myCopy(&array[e],&mergeArray[g]) ;
		e++;
		g++;
	}	
}

void mySort(int array[], unsigned int first, unsigned int last)
{ 
    int middle = 0;

    if(last > first)
    {
           middle = (first + last)/2;
	   mySort(array,middle + 1,last);
	   mySort(array,first,middle);
	   merge(array,first,middle,middle + 1,last);
    }
}