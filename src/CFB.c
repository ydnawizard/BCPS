
//CFB ENCRYPTION OPERATION
void CFB_ENCRYPT(int * KEY,int *** TEXT)
{
	//INIT IV
	int * IV = malloc(4 * sizeof(int));
	IV[0] = 1;
	IV[1] = 1;
	IV[2] = 0;
	IV[3] = 0;
	//FOR EACH BLOCK:
	for(int i = 0; i < 3; i++)
	{
		E(KEY,&IV);
		//If i > 0, XOR WITH PREV BLOCK
		if(i > 0)
		{
			for(int j = 0; j < 4; j ++)
			{
				(*TEXT)[i][j] = XOR((*TEXT)[i][j],IV[j]);
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
	}
}
