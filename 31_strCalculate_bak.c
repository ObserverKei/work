#include <stdio.h>

#define IN
#define OUT
#define INOUT


int FUNCstrCalculate(IN char *src);

int FUNCstrCalculate(IN char *src)
{
	int i = 0;
	int FirstTmp = 0;
	int NextTmp = 0;
//	if(';' == src[0] || src[0] == '\0')
//	{
//
//		return 0;
//	}
//	else
//	{
		for (i = 0; '\0' != src[i]; i++)
		{
			if('0' <= src[i] && src[i] <= '9')
			{
				FirstTmp = FirstTmp * 10 + (src[i] - '0');
			}
			else if i('0' <= src[i-1] && src[i-1] <= '9')	//fine two num
			{
				if('+' == src[i])
				{	
					for (i++; '\0' != src[i]; i++)
					{
						if('0' <= src[i] && src[i] <= '9')
						{
							NextTmp = NextTmp  + (src[i] - '0');
						}
						else if ('0' <= src[i-1] && src[i-1] <= '9')
						{
							return Tmp + FUNCstrCalculate(src+i+1);
				}
				else if ('-' == src[i])
				{
					printf("%d-", Tmp);
					return Tmp - FUNCstrCalculate(src+i+1);
				}
				else if (';' == src[i])
				{
					printf("%d", Tmp);
					return Tmp;
				}

			}
		}
		
//	}

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
