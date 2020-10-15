void mySort(int d[], unsigned int n)
{
/* variables */
int i;
int key;
int j;
/* insertion sort methood */

for (j = 1; j < n; j++)
{ 
	key = d[j];
	i = j - 1;

	while (i >= 0 && d[i]> key)
	{
		d[i + 1] = d[i];
		i = i - 1;
	}
	d[i + 1] = key;
}
}

	
	
