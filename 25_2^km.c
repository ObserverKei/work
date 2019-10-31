#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	int Tmp = 1;
	int k = 0;

	scanf("%d", &i);

	if(i > 0)
	{
		while ( Tmp <= i)
		{
			Tmp *= 2;
			k++;
		}
		printf("2^%d <= %d\n", k - 1, i);
	}
	else
	{
		printf("please check your input!\n");
	}

	return 0;
}
