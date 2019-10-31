#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	int Cnt = 0;
	int Tmp = 0;
	int Len = 0;
	char ch1[100] = {0};
	char ch2[100] = {0};
	
		
	gets(ch1);

	while('\0' != ch1[i])
	{
		ch2[i++] = ch1[i];
	}
	ch2[i] = '\0';	

	puts(ch2);

	return 0;
}
