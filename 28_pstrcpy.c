#include <stdio.h>

int main(int argc, const char *argv[])
{
	char ch[100] = {0};
	char str[100] = {0};
	char *pch = ch;
	char *pstr = str;
	char Len = 0;

	gets(ch);
	
	while ('\0' != *pch)
	{
		*pstr++ = *pch++;
	}
	*++pstr = '\0';
	
	puts(str);	//str数组名一定是常量，不会变，但是指针可以变。所以打印常量。

	return 0;
}
