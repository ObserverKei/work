#include <stdio.h>
#include <string.h>


//ASCII only
int main(int argc, const char *argv[])
{
	int i = 0;
	char c = 0;
	int Cnt[256] = {0};
	FILE *fp = NULL;

	if (2 != argc)
	{
		printf("Usage: ./Wc.out filename\n");
		return -1;
	}

	fp = fopen(argv[1], "r");
	if (NULL == fp)
	{
		perror("fail to fopen");
		return -1;
	}

	i = 0;
	while (EOF != (c = fgetc(fp)))
	{
		Cnt[c]++;
	}

	fclose(fp);

	i = 0;
	while (i < sizeof(Cnt)/sizeof(int))
	{
		if (0 != Cnt[i])
		{
			if (10 == i)
			{
				printf("\\n:\t %d \n", i, Cnt[i]);
			}
			else if (' ' == i)
			{
				printf("  :\t %d  \n", i, Cnt[i]);
			}
			else if ('\t' == i)
			{
				printf("\\t:\t %d \n", i, Cnt[i]);
			}
			else if ('\v' == i)
			{
				printf("\\v:\t %d \n", i, Cnt[i]);
			}
			else
			{
				printf("%c :\t %d \n", i, Cnt[i]);
			}
		}
		i++;
	}
//	printf("\n%c\n", 254);
	return 0;
}
