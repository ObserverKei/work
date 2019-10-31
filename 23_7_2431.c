#include <stdio.h>


int main(int argc, const char *argv[])
{
	
	int a = 0
		, b = 0
		, c = 0;
		
	printf("please input two number:\n");

	scanf("%d%d", &a, &b);
	
	c = a%10 * 1000 + b%10 * 100 + b/10%10 * 10 + a/10%10 * 1;

	printf("a = %d, b = %d,c = %d\n", a, b, c);


	return 0;
}
