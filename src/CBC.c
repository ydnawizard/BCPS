
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
			for(int j = 0; j < 3; j ++)
			{
				(*TEXT)[i][j] = XOR((*TEXT)[i][j],(*TEXT)[i][j-1]);
			}
		}
		//If i == 0, XOR WITH IV
		else
		{
			for(int j = 0; j < 3; j ++)
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
	//FOR EACH BLOCK:
	for(int i = 0; i < 3; i++)
	{
		E_INVERSE(KEY,&(*TEXT)[i]);
		//IF i > 0, XOR WITH PREV BLOCK
		if(i > 0)
		{
			for(int j = 0; j < 3; j++)
			{
				(*TEXT)[i][j] = XOR((*TEXT)[i][j],(*TEXT)[i][j-1]);
			}
		}
		else
		{
			for(int j = 0; j < 3; j++)
			{
				(*TEXT)[i][j] = XOR((*TEXT)[i][j],IV[j]);
			}
		}
	}
}
	
