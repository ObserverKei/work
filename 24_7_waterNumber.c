#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0
		, NumGe = 0
		, NumShi = 0
		, NumBai = 0
		, sum = 0;

	//printf("please input one water number: \n");
	//scanf("%d", &i);
	i = 999;

	if (i < 1000 && i > 99)
	{
		while(i > 99)
		{
			NumGe = i % 10;
			NumShi = i/10 % 10;
			NumBai = i/100 % 10;
			//printf("%d%d%d\n", NumBai, NumShi, NumGe);
			if (i == NumGe*NumGe*NumGe + NumShi*NumShi*NumShi + NumBai*NumBai*NumBai)
			{
				printf("i = %d\n", i);
			}
			i--;

		}
	}
	else
	{
		printf("please check input!\n");
	}

	return 0;
}
