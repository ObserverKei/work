#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	int Tmp = 0;
	int Len = 0;
	char ch[100] = {0};
	int Sum = 0;

	gets(ch);

	while ('\0' != ch[Len])
	{
		Len++;
	}
//	puts(ch);
	while (i < Len)
	{
		Sum += (ch[i] - '0') % 10;
		i++;
	}
	printf("%d\n", Sum);
	return 0;
}
