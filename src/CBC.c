
void CBC_ENCRYPT(int * KEY,int *** TEXT)
{
	//INIT IV
	int IV[4] = {1,1,0,0};
	//FOR EACH BLOCK:
	for(int i = 0; i < 3; i++)
	{
		//If i > 0, XOR WITH PREV BLOCK
		if(i > 0)
		{
			for(int j = 0; j < 4; j ++)
			{
				(*TEXT)[i][j] = XOR((*TEXT)[i][j],(*TEXT)[i-1][j]);
			}
		}
		//If i == 0, XOR WITH IV
		else
		{
			for(int j = 0; j < 4; j ++)
			{
				(*TEXT)[i][j] = XOR((*TEXT)[i][j],IV[j]);
			}
		}
		//E OPERATION ON CURRENT BLOCK
		E(KEY,&(*TEXT)[i]);
	}
}

void CBC_DECRYPT(int * KEY,int *** TEXT)
{
	//INIT IV
	int IV[4] = {1,1,0,0};
	int ** PRE_BLOCK = malloc(3*sizeof(int*));
	for(int i = 0; i < 3; i++)
	{
		PRE_BLOCK[i] = malloc(4*sizeof(int));
		for(int j = 0; j < 4; j++)
		{
			PRE_BLOCK[i][j] = (*TEXT)[i][j];
		}
	}
	//FOR EACH BLOCK:
	for(int i = 0; i < 3; i++)
	{
		//INVERSE E OPERATION ON CURRENT BLOCK
		E_INVERSE(KEY,&(*TEXT)[i]);
		//IF i > 0, XOR WITH PREV BLOCK
		if(i > 0)
		{
			for(int j = 0; j < 4; j++)
			{
				(*TEXT)[i][j] = XOR((*TEXT)[i][j],PRE_BLOCK[i-1][j]);
			}
		}
		else
		{
			for(int j = 0; j < 4; j++)
			{
				(*TEXT)[i][j] = XOR((*TEXT)[i][j],IV[j]);
			}
		}
	}
}
	
