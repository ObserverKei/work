#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	int Tmp = 0;
	int Len = 0;
	int Max = 0;
	int Min = 0;
	int  a[3][3] = {1, 2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
	Min = a[2][0];
	Max = a[0][0];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d\t", a[i][j]);	
			if (i == j)
			{
				if (a[i][j] > Max)
				{
					Max = a[i][j];
				}
			}
			if (2  == i + j)
			{
				if (a[i][j] < Min)
				{					
					Min = a[i][j];
				}
			}
		}
		puts("\n");
	}
	printf("Min = %d,\tMax = %d\n", Min, Max);



	return 0;
}
