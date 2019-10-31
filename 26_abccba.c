#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	int Tmp = 0;
	int Len = 0;
	char ch1[100] = {0};
	char ch = {0};

	gets(ch1);

	while ('\0' != ch1[Len])
	{
		Len++;
	}
	while (i < Len/2)
	{
		ch = ch1[i];
		ch1[i] = ch1[Len - 1 - i];
		ch1[Len - 1 - i] = ch;
		i++;
	}
	puts(ch1);

	return 0;
}
