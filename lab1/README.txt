Vincent To 500824873 

this lab was an introduction to using C to make simple sorting algorithms and getting used to using the linux terminal for
the first time.

testSort is the first compile of the lab before any edits were made to test if everything compiles

testSort2 includes the insertion sort algorithm and sorts the hardcoded data

testSort3 includes sortMain2 and implements parts from cmdlineArgsDemo
it allows it to take in arguments and sort the arguments otherwise it will sort the hardcoded data

limit to amount of arguments is 100000

last tested on tuesday jan 21 2020 and was in working order

ANSWER TO QUESTION: I would use the first value equal to 0 and the last value equal to the number of elements in the array
I would write the mySort() function as this:

mySort(int array[], int numOfElements)
{
	betterSort(array[], 0, numOfElements);
}

