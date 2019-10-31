#include <stdio.h>


int main(int argc, const char *argv[])
{
	
	int a = 0
		, b = 0
		, c = 0;
	
	printf("please input one number:\n");

	scanf("%d", &a);
	
	if (0 == a%400)printf("%d is leap yeaer \n", a);
	
	else if (0 == a%4 && 0 != a%100) printf("%d is leap yeaer \n", a);
	
	else printf("%d is common yeaer \n", a);

	
	return 0;
}
