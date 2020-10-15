#include <stdlib.h>
#include <stdio.h>

typedef struct stateMachine
{
	struct stateMachine * nextState0;
	struct stateMachine * nextState1;
	int var;
	int number;
	int deleted;
	char name;
}

fsm; 
fsm states [8];

void initialStates()
{
         states[0].name = 'A';
	 states[0].number = 0;
	 states[0].nextState0 = states + 2;
	 states[0].nextState1 = states + 1;
	 states[0].deleted = 0;
	 
	 states[1].name = 'B';
	 states[1].number = 1;
	 states[1].nextState0 = states + 7; 
	 states[1].nextState1 = states + 3; 
	 states[1].deleted = 0;

	 states[2].name = 'C';
	 states[2].number = 2;
	 states[2].nextState0 = states + 6;
	 states[2].nextState1 = states + 7;
	 states[2].deleted = 0;	
 
	 states[3].name = 'D';
	 states[3].number = 3;
	 states[3].nextState0 = states + 0;
	 states[3].nextState1 = states + 6;
	 states[3].deleted = 0;	

	 states[4].name = 'E';
	 states[4].number = 4;
	 states[4].nextState0 = states + 1;
	 states[4].nextState1 = states + 3;
	 states[4].deleted = 0;
 
	 states[5].name = 'F';
	 states[5].number = 5;
	 states[5].nextState0 = states + 4;
	 states[5].nextState1 = states + 5;
	 states[5].deleted = 0;
	 
	 states[6].name = 'G';
	 states[6].number = 6;
	 states[6].nextState0 = states + 0;
	 states[6].nextState1 = states + 5;
	 states[6].deleted = 0;
	 
	 states[7].name = 'H';
	 states[7].number = 7;
	 states[7].nextState0 = states + 5;
	 states[7].nextState1 = states + 2;
	 states[7].deleted = 0;	 
}

void printstates()
{
	int i = 0;
	for(i = 0; i <8; i++)
	{
		fprintf(stdout, "%c %c %c\n", states[i].name, states[i].nextState0->name, states[i].nextState1->name);		
	}
}

int main(int argc, char * argv[])
{
	int i; 
	int j;
	j = 0;
	//int garbageCounter;
	initialStates();
	fsm currentState = states[6]; 
	char command[3];

	fprintf(stdout, "INSTRUCTIONS \n");
	fprintf(stdout, "------------\n");
	fprintf(stdout, "Enter a command to switch states without spaces (0 or 1).\n");
	fprintf(stdout, "To see states for this machine type p.\n");
	fprintf(stdout, "To set your own path for states (ex. starting in A changing path to B when 0 when normal path is A -> C for 0)\n");
	fprintf(stdout, "Use the command c0b where c is the change command, 0 or 1 is the path, and the last character is the destination (A-H)\n");
	fprintf(stdout, "To delete a state use the command d and then followed by a state name. (ex. da)\n");
	fprintf(stdout, "To check garbage collection use the command g.\n");
	fprintf(stdout, "If you wish to terminate the program use the command q.\n");
	fprintf(stdout, "Your starting state is: %c \n", currentState.name);
 	
	while(j != 1)
	{

	  	if(command[0] == 'q'||command[0] == 'Q')
		{
	        	j = 1;
			break;
	  	}

		if(command[0] == 'p'||command[0] == 'P')
		{
			printstates();
		}

		for(i = 0; i <= 4;i++)
		{
	    		scanf("%c",&command[i]);
			if (command[i] == '\n')
			{
				break;
			}

	 	}
		
		if(command[0] == '0')
		{
			if(states[i].deleted == 1)
			{
				fprintf(stdout,"The state is deleted\n");
				break;
			}
			fprintf(stdout, "Previous State:%c\n",currentState.name);
			fprintf(stdout, "Current State:%c\n",currentState.nextState0->name);
			currentState = states[currentState.nextState0->number];
		}
	  
		if(command[0] == '1')
		{
			if(states[i].deleted == 1)
			{
				fprintf(stdout,"The state is deleted\n");
				break;
			}
			fprintf(stdout, "Previous State:%c\n",currentState.name);
			fprintf(stdout, "Current State:%c\n",currentState.nextState1->name);
			currentState = states[currentState.nextState1->number];
		}	

if (command[0] == 'd' || command[0] == 'D')
{
	if (command[1] == 'A' || command[1] == 'a')
	{
		states[0].deleted = 1; 
		fprintf(stdout, "State A deleted %c\n",states[0].deleted);
	} 

	else if (command[1] == 'B' || command[1] == 'b')
	{
		states[1].deleted = 1; 
		fprintf(stdout, "State B deleted\n");
	} 

	else if (command[1] == 'C' || command[1] == 'c')
	{
		states[2].deleted = 1; 
		fprintf(stdout, "State C deleted\n");
	} 

	else if (command[1] == 'D' || command[1] == 'd')
	{
		states[3].deleted = 1; 
		fprintf(stdout, "State D deleted\n");
	} 

	else if (command[1] == 'E' || command[1] == 'e')
	{
		states[4].deleted = 1; 
		fprintf(stdout, "State E deleted\n");
	} 

	else if (command[1] == 'F' || command[1] == 'f')
	{
		states[5].deleted = 1; 
		fprintf(stdout, "State F deleted\n");
	} 

	else if (command[1] == 'G' || command[1] == 'g')
	{
		states[6].deleted = 1; 
		fprintf(stdout, "State G deleted\n");
	} 

	else if (command[1] == 'H' || command[1] == 'h')
	{
		states[7].deleted = 1; 
		fprintf(stdout, "State H deleted\n");
	} 
}

/* if(command[0] == 'g' || command[0] == 'G')
{
	garbageCounter = 0;
	int count[7] = {0,0,0,0,0,0,0};
	for (i = 0; i<8; i++)
	{
		if (states[i].deleted == 0)
		{
			if ((((states[i].nextState0 -> name) == 'A' || ((state[i].nextState1 -> name == 'A') && states[0].deleted == 0
			{
			count[0]++;
			if ((((states[i].nextState0 -> name) == 'B' || ((state[i].nextState1 -> name == 'B') && states[0].deleted == 0
			{
			count[1]++;
			if ((((states[i].nextState0 -> name) == 'C' || ((state[i].nextState1 -> name == 'C') && states[0].deleted == 0
			{
			count[2]++;
			if ((((states[i].nextState0 -> name) == 'D' || ((state[i].nextState1 -> name == 'D') && states[0].deleted == 0
			{
			count[3]++;
			if ((((states[i].nextState0 -> name) == 'E' || ((state[i].nextState1 -> name == 'E') && states[0].deleted == 0
			{
			count[4]++;
			if ((((states[i].nextState0 -> name) == 'F' || ((state[i].nextState1 -> name == 'F') && states[0].deleted == 0
			{
			count[5]++;
			if ((((states[i].nextState0 -> name) == 'G' || ((state[i].nextState1 -> name == 'G') && states[0].deleted == 0
			{
			count[6]++;
			if ((((states[i].nextState0 -> name) == 'H' || ((state[i].nextState1 -> name == 'H') && states[0].deleted == 0
			{
			count[7]++;
			}
		}
	} */
if((command[0] == 'c'||command[0] == 'C') && command[1] == '1' && states[i].deleted != 1)
{
	if((command[2] == 'A'||command[2] == 'a') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 1 path for %c to A\n",currentState.name);
		currentState.nextState1 = states;
		states[currentState.number].nextState1 = states;
        }	

	else if((command[2] == 'B'||command[2] == 'b') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 1 path for %c to B\n",currentState.name);
		currentState.nextState1 = states + 1;
		states[currentState.number].nextState1 = states + 1;
        }

        else if((command[2] == 'C'||command[2] == 'c') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 1 path for %c to C\n",currentState.name);
		currentState.nextState1 = states + 2;
		states[currentState.number].nextState1 = states + 2;
        }

        else if((command[2] == 'D'||command[2] == 'd') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 1 path for %c to D\n",currentState.name);
		currentState.nextState1 = states + 3;
		states[currentState.number].nextState1 = states + 3;
        }

        else if((command[2] == 'E'||command[2] == 'e') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 1 path for %c to E\n",currentState.name);
		currentState.nextState1 = states + 4;
		states[currentState.number].nextState1 = states + 4;
        }

        else if((command[2] == 'F'||command[2] == 'f') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 1 path for %c to F\n",currentState.name);
		currentState.nextState1 = states + 5;
		states[currentState.number].nextState1 = states + 5;
        }

        else if((command[2] == 'G'||command[2] == 'g') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 1 path for %c to G\n",currentState.name);
		currentState.nextState1 = states + 6;
		states[currentState.number].nextState1 = states + 6;
        }	

        else if((command[2] == 'H'||command[2] == 'h') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 1 path for %c to H\n",currentState.name);
		currentState.nextState1 = states + 7;
		states[currentState.number].nextState1 = states + 7;
        }		   
}

if((command[0] == 'c'||command[0] == 'C') && command[1] == '0' && states[i].deleted != 1)
{

	if((command[2] == 'A'||command[2] == 'a') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 0 path for %c to A\n",currentState.name);
		currentState.nextState0 = states;
		states[currentState.number].nextState0 = states;
        }	

	else if((command[2] == 'B'||command[2] == 'b') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 0 path for %c to B\n",currentState.name);
		currentState.nextState0 = states + 1;
		states[currentState.number].nextState0 = states + 1;
        }

        else if((command[2] == 'C'||command[2] == 'c') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 0 path for %c to C\n",currentState.name);
		currentState.nextState0 = states + 2;
		states[currentState.number].nextState0 = states + 2;
        }

        else if((command[2] == 'D'||command[2] == 'd') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 0 path for %c to D\n",currentState.name);
		currentState.nextState0 = states + 3;
		states[currentState.number].nextState0 = states + 3;
        }

        else if((command[2] == 'E'||command[2] == 'e') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 0 path for %c to E\n",currentState.name);
		currentState.nextState0 = states + 4;
		states[currentState.number].nextState0 = states + 4;
        }

        else if((command[2] == 'F'||command[2] == 'f') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 0 path for %c to F\n",currentState.name);
		currentState.nextState0 = states + 5;
		states[currentState.number].nextState0 = states + 5;
        }

        else if((command[2] == 'G'||command[2] == 'g') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 0 path for %c to G\n",currentState.name);
		currentState.nextState0 = states + 6;
		states[currentState.number].nextState0 = states + 6;
        }	

        else if((command[2] == 'H'||command[2] == 'h') && states[i].deleted != 1)
	{
		fprintf(stdout, "Changing 0 path for %c to H\n",currentState.name);
		currentState.nextState0 = states + 7;
		states[currentState.number].nextState0 = states + 7;
        }
    }
}
	exit(0);
}




