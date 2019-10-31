#include <stdio.h>

int main(int argc, const char *argv[])
{
	char ch[100] = {0};
	int Len = 0;
	char *Head = ch;
	char *Tail = ch;
	char c = {0} ;
	gets(ch);
	while ('\0' != *Tail++)
	{

	}
	Tail--;

	for(Tail--; Head < Tail; Head++, Tail--)
	{
//		printf("%d\n", Tail - Head);
		c = *Head;
		*Head = *Tail;
		*Tail = c;
	}	
	puts(ch);

	

	return 0;
}
