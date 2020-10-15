#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern char * pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char * argv[])
{
int ch;
while ((ch = getchar()) != EOF) 
{
	if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
	continue;
	if (ch == '<') 
	{
    		if((ch = getchar()) == '/') 
		{
    			char * input = malloc (100);
    			while ((ch = getchar()) != '>') 
			{
    				if(isalpha(ch)) 
			{
    		char * flag = &ch;
    		strcat (input,flag);
    		}
    	}

	if (strcmp(input,pop()) != 0) 
	{
    		fprintf(stderr, "Invalid XML input.\n");
    		exit(1);
	}
}
    	else if (isalpha(ch)) 
	{
		char * input = malloc(100);
    		char * flag = &ch;
    		strcat(input, flag);
    		while((ch = getchar()) != '>') 
		{
    			if(isalpha(ch)) 
			{
    				flag = &ch;
    				strcat(input,flag);
    			}
    			else 
			{
    				fprintf(stderr, "Invalid XML input\n");
    				exit(1);
    			}
    		}
    		push (input);
    		memset(input, '\0', sizeof(input));
    		free(input);
    	}
    }
	else 
	{
    		fprintf(stderr,"Invalid XML input\n");
    		exit(1);
    	}
}

if(isEmpty() < 0) 
{
	printf("Valid\n");
	exit(0);
}
else 
{
	printf("Not valid\n");
	exit(1);
}
}