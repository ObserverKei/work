#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	int Tmp = 0;
	int Len = sizeof(a) / sizeof(a[0]);

	scanf("%d", &j);
	
	while (j)
	{	
		Tmp = a[Len - 1];
		for (i = 1; i < Len; i++)
		{
			a[Len - i] = a[Len - i - 1];
		}
		a[0] = Tmp;	

		j--;
	}

	for (i = 0; i < Len; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");

	return 0;
}
