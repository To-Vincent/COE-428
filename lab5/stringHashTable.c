//  
//
//

#define HASH_TABLE_SIZE 1057
int i;
typedef struct Entry Entry, *EntryPtr;
struct Entry 
{
  char * string;
  int count;
};
Entry hash_table[HASH_TABLE_SIZE];

void add(char * tag)
{
	i = 1;
	int collisionNum = 0; 
	int hashNum;
	hashNum = tag[i-1];
	while (tag[i] != '\0')
	{
		if (i<2)
		{
			hashNum = hashNum*tag[i];
		}

		else
		{
			hashNum += tag[i];
		}
		i++;
	}
	hashNum = hashNum % HASH_TABLE_SIZE; 
	collisionChecker(tag, hashNum, collisionNum);
}

void collisionChecker(char * tag, int hashNum, int colNum)
{
	Entry * temp = &hash_table[hashNum];
	if (temp->string == '\0')
	{
		temp->string = malloc(sizeof(tag));
		strcpy(temp->string,tag);
		temp->count ++;
	}

	else 
	{
		if (strcmp(temp->string,tag) == 0)
		{
			temp->count++;
		}

		else 
		{
			if (colNum == 0)
			{
				i = 1;
				hashNum = tag[i-1];
				while (tag[i] != '\0')
				{
					hashNum = hashNum*tag[i];
					hashNum = hashNum % HASH_TABLE_SIZE;
					i++;
				}
				colNum++;
				collisionChecker(tag, hashNum, colNum);
			}
			else 
			{
				for (i=0; i<HASH_TABLE_SIZE; i++)
				{
					Entry * temp2 = &hash_table[i];
					if (temp2->string == '\0')
					{
						break;
					}
				}
				collisionChecker(tag, i, colNum);
			}
		}
	}
}

void print()
{
	for (i=0; i<HASH_TABLE_SIZE; i++)
	{
		if (hash_table[i].string != '\0')
		{
			printf("%s %d\n",hash_table[i].string,hash_table[i].count);
		}
	}
}
