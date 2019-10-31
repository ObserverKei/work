#include <stdio.h>
#include <string.h>

#define IN
#define OUT
#define INOUT

void CutWordInfo(IN char *str);


/*******************************************************
 * 	函数名：CutWordInfo
 * 	功  能：分离输出单词和单词解释
 * 	参  数：char *str
 * 	返回值：无
*******************************************************/
void CutWordInfo(char *str)
{
	char *pHead = str;
	char *pTail = str;

	while (' ' != *pTail && *pTail != '\0')
	{
		pTail++;
	}
	printf("单词:");
	while (pHead < pTail)
	{
		putchar(*pHead);
		pHead++;
	}
	while (' ' == *pHead && *pHead != '\0')
	{
		pHead++;
	}
	printf("\n含义:");
	while ('\0' != *pHead)
	{
		putchar(*pHead);
		pHead++;
	}
	puts("");
	return;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	char str[512] = "apple             a kind of fruit.";`
					/*如果使用链表的话理论上没有长度限制*/

//	gets(str);

	CutWordInfo(str);
	
	return 0;
}
