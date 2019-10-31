#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define IN
#define OUT
#define INOUT

/* 反转字符串 */
char *ReStr(INOUT char *str)
{
	char *pHead = NULL;
	char *pTail = NULL;
	char Tmp = 0;

	pHead = str;
	pTail = str + strlen(str)-1;
	
	while (pHead < pTail)
	{
		Tmp = *pHead;
		*pHead = *pTail;
		*pTail = Tmp;

		pHead++;
		pTail--;
	}

	return str;
}
/*	字符串末尾补零 */
void RepNum(INOUT char *StrNum1, INOUT char *StrNum2)
{
	int i = 0;
	int StrNum1Len = strlen(StrNum1);
	int StrNum2Len = strlen(StrNum2);

	if (StrNum1Len > StrNum2Len)
	{
		while (i < StrNum1Len)
		{
			i = StrNum2Len;
			StrNum2[i] = '0';
			i++;
		}
		StrNum2[i] = '\0';
	}
	else if (StrNum1Len < StrNum2Len)
	{
		while (i < StrNum2Len)
		{
			i = StrNum1Len;
			StrNum1[i] = '0';
			i++;
		}
		StrNum1[i] = '\0';
	}

	return ;
}

/* 两个字符串数字相加 */
char *AddStrNum(IN char *StrNum1, IN char *StrNum2)
{
	int CY = 0;
	int i = 0;
	int TmpAdd = 0;
	char *AddNum = NULL;

	AddNum = (char *)malloc(128);
	memset(AddNum, 0, 128);

	/* 反转字符串 */
	ReStr(StrNum1);
	ReStr(StrNum2);

	/*	字符串末尾补零 */
	RepNum(StrNum1, StrNum2);

	/*	开始按位求和  */
	while (i < strlen(StrNum1) || i < strlen(StrNum2))
	{
		TmpAdd = StrNum1[i] - '0' + StrNum2[i] - '0' + CY;
		AddNum[i] = TmpAdd%10 + '0';
		CY = 0;

		if (TmpAdd > 9)
		{
			CY = 1;
		}

		i++;
	}

	if (0 != CY)
	{
		AddNum[i] = CY + '0';
		CY = 0;
		i++;
	}

	AddNum[i] = '\0';
	
	/* 反转字符串 */
	ReStr(AddNum);
	

	return AddNum;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	char StrNum1[128] = {"123456789123456789"};
	char StrNum2[128] = {"11111111111111111"};

	puts(AddStrNum(StrNum1, StrNum2));
	
	puts("Please enter two Numbers:");
	gets(StrNum1);
	gets(StrNum2);
	
	puts(AddStrNum(StrNum1, StrNum2));

	return 0;
}
