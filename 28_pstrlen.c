#include <stdio.h>

int main(int argc, const char *argv[])
{
	char ch[100] = {0};
	char *p = ch;
	char Len = 0;
	
	gets(ch);
	while ('\0' != *p++)
	{
		Len++;
	}
	printf("Len = %d\n", Len);

	return 0;
}
