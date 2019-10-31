#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	int a[55] = {0};
	int Tem = 0;
	int Len = sizeof(a) / sizeof(a[0]);

	for (i = 0; i < Len; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (i = 0; i < Len/2; i++)
	{
		Tem = a[i];
		a[i] = a[Len - i - 1];
		a[Len - i - 1] = Tem;

	}

	for (i = 0; i < Len; i++)
	{
		printf("%d\n", a[i]);
	}

	return 0;
}
