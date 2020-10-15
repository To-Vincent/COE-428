#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int isEmpty();
extern int pop();
extern void push(int);

int main(int argc, char * argv[])
{
	int ch;
	int nextCh;
	int popped;
	int i = 0;
	int letters['z' + 1];
	
	for (i = 'a';i <= 'z'; i++)
	{
		letters[i] = 0;
	}

while ((ch = getchar()) != EOF) 
{
	if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
	continue;
		if((ch == '<')) 
		{
			ch = getchar();
			if(ch == '/') 
			{
				ch = getchar();
				nextCh = getchar();
        			if(nextCh == '>' && isalpha(ch)) 
				{
                			popped = pop();
                			if(popped == -1) 
					{
                				exit(1);
              				}
         			else 
				{
                 			if(popped != ch) 
					{
                          			fprintf(stderr, "Invalid XML Expression.");
                          			exit(1);
                  			}
          			}
        		}
		else 
		{
       			fprintf(stderr, "Invalid");
        		exit(1);
        	}
      		}

      	else if (isalpha(ch)) 
	{
        	nextCh = getchar();
        	if(nextCh == '>' && isalpha(ch)) 
		{
                	push(ch);
                	letters[ch]++;
       		}
       		else 
		{
             		fprintf(stderr, "Invalid XML expression.");
              		exit(1);
        	}

	}

	else if(ch == EOF) 
	{
        	fprintf(stderr, "Invalid XML expression.");
        	exit(1);
      	}
	}
}

if((isEmpty()) < -1) 
{
	for(i = -1; i < 25 ; i++) 
	{
		if (letters[i] != 0)
		{
			printf("%c : %d\n", (97 + i), letters[i]);
		}
	}
	printf("Valid\n");
  	exit(0);
}
else 
{
	printf("Invalid\n");
  	exit(1);
}
}
