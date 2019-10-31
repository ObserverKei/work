#include <stdio.h>
#include <string.h>

#define IN
#define OUT
#define INOUT

int FindStrWord(IN char *str, IN char *word);

/*****************************************************
 * 	函数名：FindStrWord
 * 	功  能：寻找字符串中单词出现的次数
 * 	参  数：
 * 		char *str	字符串首地址
 * 		char *word	单词首地址
 *	返回值：
 *		成功返回	单词出现的次数
*****************************************************/
int FindStrWord(IN char *str, IN char *word)
{
	int Cnt = 0;
	int i = 0;
	int j = 0;

	for (Cnt = 0, i = 0, j = 0; j < strlen(str); j++)
	{
		if (word[i] == str[j])
		{

		}
		else
		{
			i = 0;
		}
		if (word[i] == str[j])
		{
			if (i == strlen(word)-1)
			{
				i = 0;
				Cnt++;
			}
			else
			{
				i++;
			}
		}
	}

	return Cnt; 
}



int main(int argc, const char *argv[])
{
	int i = 0;
	char str[512] = "fdsafdsafdsafdsahellofdsahellofdsahelhellohello";
	char word[512] = {"hello"};
#if 0 
	puts("please input str:");
	gets(str);
	puts("please input word:");
	gets(word);
#endif
	puts(str);
	puts(word);

	printf("Cnt = %d\n", FindStrWord(str, word));


	return 0;
}
