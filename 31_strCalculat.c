#include <stdio.h>

#define IN
#define OUT
#define INOUT

int FUNCstrCalculate(IN char *src);

int FUNCstrCalculate(IN char *src)
{
	int i = 0;
	int Tmp = 0;
	
	if('+' == src[0])
	{
		for (i = 1; '\0' != src[i]; i++)
		{
			if('0' <= src[i] && src[i] <= '9')
			{
				Tmp = Tmp * 10 + (src[i] - '0');
			}

			else if ('0' <= src[i-1] && src[i-1] <= '9')	
			{
				printf("+%d", Tmp);
				return FUNCstrCalculate(src+i) + Tmp;
			}
		}
	}
	else if('-' == src[0])
	{
		for (i = 1; '\0' != src[i]; i++)
		{
			if('0' <= src[i] && src[i] <= '9')
			{
				Tmp = Tmp * 10 + (src[i] - '0');
			}

			else if ('0' <= src[i-1] && src[i-1] <= '9')
			{
				printf("-%d", Tmp);
				return FUNCstrCalculate(src+i) - Tmp;
			}
		}
	}
	else if('0' <= src[0] && src[0] <= '9')
	{
		for (i = 0; '\0' != src[i]; i++)
		{
			if('0' <= src[i] && src[i] <= '9')
			{
				Tmp = Tmp * 10 + (src[i] - '0');
			}

			else if ('0' <= src[i-1] && src[i-1] <= '9')	//fine two num
			{
				printf("%d", Tmp);
				return Tmp + FUNCstrCalculate(src+i);
			}
		}
	}

	return 0;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
	char ch[100];
	
	gets(ch);

	ret = FUNCstrCalculate(ch);
	printf("=%d\n", ret);
	printf("%s\b=%d\n", ch, ret);

	return 0;
}
