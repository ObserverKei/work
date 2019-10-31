#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0, j = 0;

	for (i = 99; i < 1000; i++)
	{
		if(6 == i % 10 && 0 == i % 3 )
		{
			
			printf("%d\t", i);j++;
			if (0 == j % 8) 
			{
				printf("\n");
			}

		}
	}

	printf("\ntimes = %d\n", j);

	return 0;
}
