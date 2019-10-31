#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *FindRepStr(char *str)
{
	char *pRetHeadStr = NULL;
	int Cnt = 0;
	int MaxLen = 0;
	char *pTmpHead = NULL;
	char *pTmp = NULL;
	
	pTmp = str;
	while ('\0' != pTmp)
	{
		Cnt = 0;
		pTmpHead = pTmp;
		while (*pTmpHead == *pTmp)
		{
			Cnt++;
		}
		if (Cnt > MaxLen)
		{
			pRetHeadStr = pTmpHead;
			MaxLen = Cnt; 
		}
	}
}

int main(int argc, const char *argv[])
{
	int i = 0;
	char str[4096] = {0};

	puts("请输入字符串");

	gets(str);


	return 0;
}
