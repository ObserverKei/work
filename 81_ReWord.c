#include <stdio.h>
#include <string.h>

#define IN
#define OUT 
#define INOUT

int ReWord(INOUT char *src);

int ReWord(INOUT char *src)
{
	int i = 0;
	int Cnt = 0;
	int Len = strlen(src);
	char Tmp = '\0';
	int Head = 0;
	int Tail = 0;
	
	for (i = 0; i < Len / 2 ; i++)
	{
		Tmp = src[i];
		src[i] = src[Len-i-1];
		src[Len-i-1] = Tmp;
	}

	for (Head = 0, i = 0; '\0' != src[i]; i++)
	{
		if ('a' <= src[i] && src[i] <= 'z' || 'A' <= src[i] && src[i] <= 'Z')
		{
 			if (!('a' <= src[i+1] && src[i+1] <= 'z' || 'A' <= src[i+1] && src[i+1] <= 'Z'))
			{
				for (Tail = i; Head < Tail; Head++, Tail--)
				{
					Tmp = src[Head];
					src[Head] = src[Tail];
					src[Tail] = Tmp;
				}
			}
 			if (!('a' <= src[i-1] && src[i-1] <= 'z' || 'A' <= src[i-1] && src[i-1] <= 'Z'))
			{
				Head = i;
			}
		}
	}
	return 0;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	char ch[100] = {0};

	gets(ch);
	ReWord(ch);

	puts(ch);


	return 0;
}
