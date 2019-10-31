#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	int max = 0;
	double score = 0;
	int min = 0;
	int Tmp = 0;	

	printf("please input score (you can exit by -1 ) : \n");
	while (-1 != i)
	{
		scanf("%d", &i);
		if (0 == j)
		{
			max = min = i;
		}

		if (-1 != i)
		{
			if (i > max)
			{
				max = i;
			}
			if (i < min)
			{
				min = i;
			}
			
			score += i;
			
			j++;
		}
	}

	score -= min + max;
	score /= j - 2;
	
	printf("score = %.2lf\n", score);
	#if 0
	printf("min = %d\n", min);
	printf("max = %d\n", max);
	#endif

	return 0;
}
