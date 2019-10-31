#include <stdio.h>
#include <string.h>

#define IN
#define OUT 
#define INOUT

int ReWord(INOUT char **src);

int ReWord(INOUT char **src)
{
	int i = 0;
	int Cnt = 0;
	int Len = strlen(*src);
	char Tmp = '\0';
	
	for (i = 0; i < Len / 2 ; i++)
	{
		Tmp = (*src)[i];
		(*src)[i] = (*src)[Len-i-1];
		(*src)[Len-i-1] = Tmp;
	}
	return 0;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	char ch[100] = {0};

	gets(ch);

	puts(ch);


	return 0;
}
