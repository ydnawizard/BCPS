
//CFB ENCRYPTION OPERATION
void CFB_ENCRYPT(int * KEY,int *** TEXT)
{
	//INIT IV
	int * IV = malloc(4 * sizeof(int));
	IV[0] = 1;
	IV[1] = 1;
	IV[2] = 0;
	IV[3] = 0;
	//INIT BLOCK PLACE HOLDER
	int * BLOCK_PREV = malloc(4 * sizeof(int));
	//FOR EACH BLOCK:
	for(int i = 0; i < 3; i++)
	{
		//If i > 0, XOR WITH PREV BLOCK
		if(i > 0)
		{
			for(int j = 0; j < 4; j++)
			{
				BLOCK_PREV[j] = (*TEXT)[i-1][j];
			}
			E(KEY,&BLOCK_PREV);
			for(int j = 0; j < 4; j ++)
			{
				(*TEXT)[i][j] = XOR((*TEXT)[i][j],BLOCK_PREV[j]);
			}
		}
		//If i == 0, XOR WITH IV
		else
		{
			E(KEY,&IV);
			for(int j = 0; j < 4; j ++)
			{
				(*TEXT)[i][j] = XOR((*TEXT)[i][j],IV[j]);
			}
		}
		//E OPERATION ON CURRENT BLOCK
	}
	free(IV);
	free(BLOCK_PREV);
}

//CFB DECRYPTION OPERATION
void CFB_DECRYPT(int * KEY,int *** TEXT)
{
	//INIT IV
	int * IV = malloc(4 * sizeof(int));
	IV[0] = 1;
	IV[1] = 1;
	IV[2] = 0;
	IV[3] = 0;
	int ** PRE_BLOCK = malloc(3*sizeof(int*));
	for(int i = 0; i < 3; i++)
	{
		PRE_BLOCK[i] = malloc(4*sizeof(int));
		for(int j = 0; j < 4; j++)
		{
			PRE_BLOCK[i][j] = (*TEXT)[i][j];
		}
	}
	for(int i = 0; i < 3; i ++)
	{
		if(i > 0)
		{
			E(KEY,&PRE_BLOCK[i-1]);
			for(int j = 0; j < 4; j++)
			{
				(*TEXT)[i][j] = XOR((*TEXT)[i][j],PRE_BLOCK[i-1][j]);
			}
		}
		else
		{
			E(KEY,&IV);
			for(int j = 0; j < 4; j++)
			{
				(*TEXT)[i][j] = XOR((*TEXT)[i][j],IV[j]);
			}
		}
	}
}
