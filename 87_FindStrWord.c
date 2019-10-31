#include<stdio.h>

#define IN
#define OUT
#define INOUT

char *FindStrWord(IN char *str, IN char *word);

/***********************************************
 * 	任务名：FindStrWord
 * 	功  能：查找字符串中匹配单词首地址
 * 	参  数：
 * 		char *str 		字符串
 * 		char *word		单词
 * 	返回值：
 * 		找到返回	匹配的单词首地址
 * 		未找返回	NULL
***********************************************/
char *FindStrWord(IN char *str, IN char *word)
{
	char *pTmpStr = NULL;
	char *pTmpWord = NULL;
	while ('\0' != *str)
	{
		if (*str = *word)
		{
			pTmpStr = str;
			pTmpWord = word;
			while (*pTmpStr == *pTmpWord && '\0' != *pTmpStr)
			{
				pTmpStr++;
				pTmpWord++;
			}
			if ('\0' == *pTmpWord)
			{
				return str;
			}
			else
			{
				str++;
			}
		}
		else
		{
			str++;
		}
	}

	return NULL;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	char str[512] = {0};
	char word[100] = {0};

	gets(str);
	gets(word);

	puts(FindStrWord(str, word));
	
	return 0;
}
