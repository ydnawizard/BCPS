//e block/inverse e block functions and their components
//the XOR function is also utilized in other project files so this include 
//has to precede the others in the header

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

//LEFT-SHIFT OP
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

//SINGLE BLOCK E OP
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

//RIGHT-SHIFT OP
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

//INVERSE E OP
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
