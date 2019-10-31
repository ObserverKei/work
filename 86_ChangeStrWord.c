#include <stdio.h>
#include <string.h>


#define IN
#define OUT
#define INOUT

char *ChangeStrWord(INOUT char *str, IN char *word, IN char *ChWord);

/*****************************************************
 * 	函数名：ChangeStrWord
 * 	功  能：替换字符串中的单词
 * 	参  数：
 * 		char *str	 字符串首地址
 * 		char *word	 单词首地址
 * 		char *ChWord 替换后单词首地址
 *	返回值：
 *		成功返回	字符串首地址
*****************************************************/
char *ChangeStrWord(INOUT char *str, IN char *word, IN char *ChWord)
{
	int Cnt = 0;
	int i = 0;
	int j = 0;
	char *SaveHead = NULL;
	int Tmp = 0;
	SaveHead = str;
	
	for (Cnt = 0, i = 0, j = 0; j < strlen(SaveHead); j++)
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
				Tmp = strlen(&str[j])+strlen(ChWord)-strlen(word);							
				//记录相对j的尾部距离								
				memmove(&str[j]-strlen(word)+strlen(ChWord)+1, &str[j]+1, strlen(&str[j]+1));	
				//让字符串整体后移
				str[j+Tmp] = '\0';																
				//加上字符串结束标志
				memmove(&str[j]-strlen(word)+1, ChWord, strlen(ChWord));						
				//把新词复制进去
				j += strlen(ChWord)- strlen(word);												
				//让str[j]为加入新词后的末位
			}
			else
			{
				i++;
			}
		}
	}

	printf("tmp = %d\n", Cnt);
	return SaveHead; 
}



int main(int argc, const char *argv[])
{
	int i = 0;
	char str[512] = "fdsafdsafdsafdsahellofdsahellofdsahelhellohello";
	char word[512] = {"hello"};
	char ChWord[512] = {"hi"};
#if 0  
	puts("please input str:");
	gets(str);
	puts("please input word:");
	gets(word);
	puts("please input ChWord:");
	gets(ChWord);
#endif
	puts(str);
	puts(word);
	puts(ChWord);

	printf("%s\n", ChangeStrWord(str, word, ChWord));


	return 0;
}
