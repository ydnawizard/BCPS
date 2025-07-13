#include "src/main.h"

//SEEDS/RESETS THE TEXT POINTER
void seedTEXT(int *** TEXT)
{
	(*TEXT)[0][0] = 1;
	(*TEXT)[0][1] = 1;
	(*TEXT)[0][2] = 1;
	(*TEXT)[0][3] = 1;
	(*TEXT)[1][0] = 0;
	(*TEXT)[1][1] = 1;
	(*TEXT)[1][2] = 0;
	(*TEXT)[1][3] = 0;
	(*TEXT)[2][0] = 0;
	(*TEXT)[2][1] = 1;
}

int main() 
{
	int KEY[4] = {1,0,1,1};
	int ** TEXT;
	TEXT = malloc(3 * sizeof(char*));
	for(int i = 0; i < 3; i++)
	{
		TEXT[i] = malloc(12 * sizeof(char));
	}
	seedTEXT(&TEXT);
	printf("%s\n","ORIGINAL PLAINTEXT:");
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			printf("%d",TEXT[i][j]);
		}
		printf("\n");
	}
	CBC_ENCRYPT(KEY,&TEXT);
	printf("%s\n","TEXT AFTER CBC:");
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			printf("%d",TEXT[i][j]);
		}
		printf("\n");
	}
	CBC_DECRYPT(KEY,&TEXT);
	printf("%s\n","TEXT AFTER CBC DECRYPTION:");
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			printf("%d",TEXT[i][j]);
		}
		printf("\n");
	}

}
