//SHIFT OP
void SHIFT_INVERSE(int ** BLOCK)
{
	//RETAIN INDEX 3
	int mem = (*BLOCK)[3];
	//SHIFT RIGHT
	for(int i = 3; i > 0; i--)
	{
		(*BLOCK)[i] = (*BLOCK)[i-1];
	}
	//SEND MEM TO INDEX 0
	(*BLOCK)[0] = mem;
}

void E_INVERSE(int * KEY, int ** BLOCK)
{
	//XOR
	for(int i = 0; i < 4; i++)
	{
		(*BLOCK)[i] = XOR((*BLOCK)[i],KEY[i]);
	}
	//SHIFT
	SHIFT_INVERSE(&(*BLOCK));
}
