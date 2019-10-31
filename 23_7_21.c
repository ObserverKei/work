#include <stdio.h>


int main(int argc, const char *argv[])
{
	
	int a = 0
		, b = 0
		, c = 0;
	
	printf("please input one number:\n");

	scanf("%d", &a);

	printf(0 == a%2 ? "a = %d is a even\n" : "a = %d is a odd\n", a);

	
	return 0;
}
