#include <stdio.h>
//#include <string.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	int Tmp = 0;
	char ch1[100] = {0};
	char ch2[100] = {0};

	puts("please input two string:");
	gets(ch1);
	gets(ch2);

	while (('\0' != ch1[i] || '\0' != ch2[i]) && !(Tmp = (ch1[i] - ch2[i])))
	{
		i++;
	}
	if (Tmp > 0)
	{
		puts("1");
	}
	if (0 == Tmp)
	{
		puts("0");
	}
	if (Tmp < 0)
	{
		puts("-1");
	}

//	printf("%d\n", strcmp(ch1, ch2));
	
	return 0;
}
