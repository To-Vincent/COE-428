#include "mySort.h"
#include "metrics.h"

void mySort(int array[], unsigned int first, unsigned int last)
    {
	int i;
	int j;
	int key;

	for (i = first; i < last+1 ; i++)
	{ 
		key = array[i];
		j = i - 1;

		while (j >= 0 && (myCompare(array[j],key) > 0))
		{
			mySwap(&array[j], &array[j+1]);
			j = j - 1;
		}
		myCopy(&key,&array[j + 1]);
	}
    }

