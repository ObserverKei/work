#include <stdio.h>


int main(int argc, const char *argv[])
{
	int i = 0;
	int Cnt = 0;
	char Tmp = 0;
	FILE *fp = 0;

	if (2 != argc)
	{
		fprintf(stderr, "Usage: ./a.out filename");
		return -1;
	}

	fp = fopen(argv[1], "r");
	if (NULL == fp)
	{
		perror("fail to fopen");
		return -1;
	}

	while (EOF != (Tmp = fgetc(fp)))
	{
		if ('\n' == Tmp)
		{
			Cnt++;
		}
	}
	
	printf("linage: %d\n", Cnt);

	fclose(fp);

	return 0;
}
