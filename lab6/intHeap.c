/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */


/**
 * deleteHeap() removes the biggest integer in the heap and returns it.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <tgmath.h>

int size = 0;
int heap [1000];

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
	return size;
}

void printHeap(int position)
{
	int next;

	printf("<nodeid = %d>\n", heap[position]);

	next = (2 * position) + 1;
	if (next < heapSize()) 
	{
		printHeap(next);
	}

	next = (2 * position) + 2;
	if (next < heapSize()) 
	{
		printHeap(next);
	}

	printf("</node>\n");
}

void sortHeap(int i)
{
	int temp;
	int largest;
	int right;
	int left;

	right = (2 * i) + 2;
	left = (2 * i) + 1;
	
	if ((heap[i] < heap[left]) && (left < heapSize()))
	{
		largest = left;
	}

	else
	{
		largest = i;
	}
	
	if ((heap[largest] < heap[right]) && (right < heapSize()))
	{
		largest = right;
	}

	if (largest != i)
	{
		sortHeap(largest);
		temp = heap[largest];
		heap[largest] = heap [i];
		heap[i] = temp;
	}
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
	int temp;
	int i;
	int parent;

	i = heapSize();
	parent = (i-1)/2;
	heap[size] = thing2add;

	while ((heap[parent] < thing2add) && (parent >= 0))
	{
		temp = heap[parent];
		heap[parent] = heap[i];
		heap[i] = temp;
		i = parent;
		parent = (i-1)/2;
	}
	size++;
}

int deleteHeap()
{
	int max = heap[0];
	size--;
	heap[0] = heap[size];
	sortHeap(0);
	return max;
}
