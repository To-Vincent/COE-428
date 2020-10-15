#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern int pop();
extern void push(int);
extern void addHeap(int);
extern int deleteHeap();
extern void sortHeap();
extern int heapSize();
extern int isEmpty();
extern void printHeap(int);

int main(int argc, char * argv[])
{
	int count;
	int value;
	int i;
	int j;

	count = 0;

	while (scanf("%d\n", &value) != EOF) 
	{
		fprintf(stderr, "Taking input: %d\n", value);
		addHeap(value);
		count++;
	}
	
	printHeap(0);

	j = heapSize();
	
	for (i = 0; i < j; i++)
	{
		int temp;
		temp = deleteHeap();
		printf("%d\n", temp);
		push(temp);
    	}
	
	printf("\n");
	for (i = 0; i < count; i++)
	{
		printf("%d\n", pop());
	}

	exit(0);
}
