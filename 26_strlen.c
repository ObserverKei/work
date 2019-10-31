#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	int Tmp = 0;
	char ch[100];
	int Len = 0;

	printf ("please input one string:\n");

	gets(ch);
	
	while ('\0' != ch[i])
	{
		Len = 1 + i++;
	}
	printf("strlen = %d\n", Len);

	return 0;
}
