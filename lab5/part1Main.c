#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
int ch;
int popped;
int nextCh;

while ((ch = getchar()) != EOF)
{
	if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
	continue;
  		if ((ch == '<'))
		{
  			ch = getchar();
  			if (ch == '/') 
			{
  				ch = getchar();
  				nextCh = getchar();
  				if (nextCh == '>' && isalpha(ch)) 
				{
  					popped = pop();
  					if (popped == -1) 
					{
  						exit(1);
  					}
  				else 
				{
  					if (popped != ch) 
					{
  						fprintf(stderr, "Invalid XML expression.");
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
  			if (nextCh == '>' && isalpha(ch) )
			{
  				push(ch);
			}
  			else 
			{
  				fprintf(stderr, "Invalid XML expression");
  				exit(1);
  			}
  		}
  		else if(ch == EOF) 
		{
  			fprintf(stderr, "Invalid XML expression");
  			exit(1);
  		}
	}  
}

if(isEmpty() > 0) 
{
    printf("Not Valid\n");
    exit(1);
}
else 
{
    printf("Valid\n");
    exit(0);
}
}

