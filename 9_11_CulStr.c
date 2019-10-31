#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <mytypes.h>

int IsSymbol(char *pChArg)
{			
	switch (*pChArg)
	{
		case '+':;
		case '-':;
		case '*':;
		case '/':return 1;
	}

	return 0;
}


int CmpSymbol(char *pChArg)
{
	switch (*pChArg)
	{
		case '+':;
		case '-':return 0;
		case '*':;
		case '/':return 1;
	}
	
	return -1;
}

int CulNumSymbol(int Num1Arg, int Num2Arg, char SymbolArg)
{
	switch (SymbolArg)
	{
		case '+':Num1Arg += Num2Arg;break;
		case '-':Num1Arg -= Num2Arg;break;
		case '*':Num1Arg *= Num2Arg;break;
		case '/':Num1Arg /= Num2Arg;break;
	}

	return Num1Arg;
}

int ExecCul(char *StrNumArg)
{
	int TmpNum = 0;
	DataType Num;
	DataType Symbol;
	DataType TmpCmpCh;
	char *pTmp = NULL;
	char *pEnd = NULL;
	SEQSTACK_S *pseqstack_symbol = NULL;
	SEQSTACK_S *pseqstack_num = NULL;

	pseqstack_symbol = SeqStack.Create(10);
	if (NULL == pseqstack_symbol)
	{
		perror("fail to SeqStack Create");
		return -1;
	}

	pseqstack_num = SeqStack.Create(10);
	if (NULL == pseqstack_num)
	{
		perror("fail to SeqStack Create");
		return -1;
	}

	pEnd = StrNumArg;

	while ('\0' != *pEnd || '\0' != pEnd[-1])
	{
		pTmp = pEnd;
		while ('\0' != *pTmp)
		{
			if (IsSymbol(pTmp) && '\0' != *pTmp)
			{
				printf("break \n");
				break;
			}
			pTmp++;
		}
		sscanf(pEnd, "%d", &Num.Num);
		SeqStack.Push(pseqstack_num, &Num);

		Symbol.Symbol = *pTmp;
		
		if (( ! SeqStack.IsEmpty(pseqstack_symbol)) || ( ! (CmpSymbol(&TmpCmpCh.Symbol) < CmpSymbol(&Symbol.Symbol)))
		















		if ( ! SeqStack.IsEmpty(pseqstack_symbol))
		{
			TmpCmpCh.Symbol = SeqStack.Pop(pseqstack_symbol).Symbol;
			printf("%c\n", TmpCmpCh.Symbol);
			while ( ! (CmpSymbol(&TmpCmpCh.Symbol) < CmpSymbol(&Symbol.Symbol)))
			{
				TmpNum = SeqStack.Pop(pseqstack_num).Num;
				Num.Num = TmpNum;
				if ( ! SeqStack.IsEmpty(pseqstack_symbol))
				{
					TmpCmpCh.Symbol = SeqStack.Pop(pseqstack_symbol).Symbol;
				}
				else
				{
					break;
				}
			}
			SeqStack.Push(pseqstack_symbol, &TmpCmpCh);
		}

		pEnd = pTmp+1;

		if (*pEnd == '\0' || pEnd[-1] == '\0')
		{
			TmpNum = SeqStack.Pop(pseqstack_num).Num;
			printf("%d \n", TmpNum);
			TmpCmpCh = SeqStack.Pop(pseqstack_symbol);
			switch (TmpCmpCh.Symbol)
			{
			case '+':TmpNum += Num.Num;break;
			case '-':TmpNum -= Num.Num;break;
			case '*':TmpNum *= Num.Num;break;
			case '/':TmpNum /= Num.Num;break;
			}
			return TmpNum;			
		}
		else
		{
			SeqStack.Push(pseqstack_num, &Num);
			SeqStack.Push(pseqstack_symbol, &Symbol);
		}
	}

	return SeqStack.Pop(pseqstack_num).Num;
}

int main(int argc, const char *argv[])
{
	char StrNum[128] = {"123+21*3-2+5/2"}; //=186

	puts(StrNum);
	printf("%d \n", ExecCul(StrNum));

	puts("please input str cul num");
	gets(StrNum);
	printf("%d \n", ExecCul(StrNum));

	return 0;
}
