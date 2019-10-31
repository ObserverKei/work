#include <string.h>
#include <stdio.h>

char *FindRepStr(char *str)
{
	int i = 0;
	int RepStrHead = 0;
	int TmpLen = 0;
	int MaxLen = 0;
	int Tmp = 0;
	
	while (i < strlen(str))
	{
		Tmp = i;
		TmpLen = 0;

		while (str[Tmp] == str[i] && i < strlen(str))
		{
			TmpLen++;
			i++;
		}
		if (TmpLen > MaxLen)
		{
			MaxLen = TmpLen;
			RepStrHead = Tmp;
			TmpLen = 0;
		}
	}
	
	str[RepStrHead + MaxLen] = '\0';

	return str + RepStrHead;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	char str[4096] = {0};
	char *pTmp = NULL;

	gets(str);

	pTmp = FindRepStr(str);

	puts(pTmp);
	
	return 0;
}
