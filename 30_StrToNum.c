#include <stdio.h>

#define IN
#define OUT
#define INOUT

int StrToNum(IN char *src);

int StrToNum(IN char *src)
{
	int Tmp = 0;
	if('-' != *src)
	{
		while('\0' != *src)
		{
			Tmp = Tmp * 10 + (*src - '0');
			src++;
		}	

		return Tmp;
	}
	else if('-' == *src)
	{
		src++;
		return -StrToNum(src);
	}
	return 0;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	char src[100] = {0};
	int Ret = 0;

	puts("请输入一串数字：");
	gets(src);

	printf("Ret = %d\n", StrToNum(src));

	return 0;
}
