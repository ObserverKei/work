#include <stdio.h>

int main(int argc, const char *argv[])
{
	char ch[100] = {0};
	char str[100] = {0};
	char *pch = ch;
	char *pstr = str;
	int Cnt = 0;

	gets(ch);
	gets(str);
	while (!(Cnt = (*pch++ - *pstr++)) && '\0' != *pch)
	{

	}
	if (0 == Cnt)
	{
		puts("0");
	}
	if (Cnt > 0)
	{
		puts("1");
	}
	if (Cnt < 0)
	{
		puts("-1");
	}


	return 0;
}
