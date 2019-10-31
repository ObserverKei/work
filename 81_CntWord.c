#include <stdio.h>

#define IN
#define	OUT
#define INOUT

int CntWord(IN char *src);

int CntWord(IN char *src)
{
	int i = 0;
	int Cnt = 0;

	for (i = 0; '\0' != src[i]; i++)
	{
		if ('a' <= src[i] && src[i] <= 'z' || 'A' <= src[i] && src[i] <= 'Z')
		{
			
		}
		else if ('a' <= src[i-1] && src[i-1] <= 'z' || 'A' <= src[i-1] && src[i-1] <= 'Z')
		{
			Cnt++;
		}
	}
	if (' ' == src[i-1])
	{
		return Cnt;
	}
	return Cnt + 1;
}


int main(int argc, const char *argv[])
{
	int i = 0;
	char ch[100] = {0};

	gets(ch);
	printf("Cnt = %d\n", CntWord(ch));
	return 0;
}
