#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	int Tmp = 0;
	int Len = 0;
	int Len2 = 0;
	char ch1[100] = {0};
	char ch2[100] = {0};
	char ch3[100] = {0};

	puts("please input two string:\n");
	gets(ch1);
	gets(ch2);

	while ('\0' != ch1[i])
	{
		Len = 1 + i++;
	}
	
	while ('\0' != ch2[j])
	{
		 ch1[i++] = ch2[j++];
	}
	
	ch1[i] = '\0';
	puts(ch1);
	
	
	return 0;
}
