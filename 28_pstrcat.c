#include <stdio.h>

int main(int argc, const char *argv[])
{
	char ch[100] = {0};
	char str[100] = {0};
	char *pch = ch;
	char *pstr = str;
	int Len = 0;
	int Cnt = 0;

	puts("please input two string:");
	gets(ch);
	gets(str);

	while ('\0' != *pch++)
	{

	}	
	pch--;	//这是为了保证pch指向字符串结束标志
//	pch = &ch[strlen(ch)];	//这样写也可以。
//
	while ('\0' != *pstr)
	{
		*pch++ = *pstr++;
	}
	*pch = '\0';	//数组不一定会被赋值{0}，防止无结束标志。
	puts(ch);	//输出是ch，而不是pch，pch此时指向字符串末端
	
	return 0;
}
