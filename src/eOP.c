//SIMPLE XOR OP
int XOR(int bit1,int bit2)
{
	int result;
	if(bit1 == bit2)
	{
		result = 0;
	}
	else
	{
		result = 1;
	}
	return result;
}

//SHIFT OP
void SHIFT(int ** BLOCK)
{
	//PAD IF NEEDED
	for(int i = 0; i < 4; i++)
	{
		if((*BLOCK)[i] ==  -1)
		{
			(*BLOCK)[i] = 0;
		}
	}
	//RETAIN INDEX 0
	int mem = (*BLOCK)[0];
	//SHIFT LEFT
	for(int i = 0; i < 3 ; i++)
	{
		(*BLOCK)[i] = (*BLOCK)[i + 1];
	}
	//SEND MEM TO INDEX 3
	(*BLOCK)[3] = mem;
}

//SINGLE BLOCK E OPERATION
void E(int * KEY, int ** BLOCK)
{
	//SHIFT
	SHIFT(&(*BLOCK));
	//XOR
	for(int i = 0; i < 4; i++)
	{
		(*BLOCK)[i] = XOR((*BLOCK)[i],KEY[i]);
	}
}

