#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	FILE *fpdict = NULL;
	char word[100] = {0};
	char *pTmp = NULL;
	char LineDict[4096] = {0};
	//规定每行不超过4096-1-1个
	
	puts("please input a word:");
	gets(word);

	fpdict = fopen("dict.txt", "r");
	if (NULL == fpdict)
	{
		perror("fail to ./dict fopen");
		return -1;
	}
	
	while (NULL != fgets(LineDict, sizeof(LineDict), fpdict))
	{
		if (0 == strncmp(word, LineDict, strlen(word)))
		{
			pTmp = LineDict + strlen(word);
			if (' ' == pTmp[0] && ' ' == pTmp[1])
			{
				while (' ' == *pTmp)
				{
					pTmp++;
				}
				puts(pTmp);
				return 0;
			}
		}
	}
	puts("Not included in the dict!");
	fclose(fpdict);

	return 0;
}
