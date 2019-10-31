#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0
		, sum = 0
		, n[3] = {1 , 1 , 2};
	
	printf("please input one number\n");
	scanf("%d", &i);

	if (1 == i)
	{
		sum = 1;
		printf("an = 1\n");
	}
	else if (2 == i)
	{
		
		sum = 1;
		printf("an = 1\n");
	}
	else if (i > 2)
	{

		i -= 3;	
		for (i; i >= 0; i--) 
		{
			n[2] = n[0] = n[0] + n[1];
			n[0] = n[1]; 
			n[1] = n[2];
		}
		printf("an = %d\n", n[1]);
	}
	
	return 0;
}
