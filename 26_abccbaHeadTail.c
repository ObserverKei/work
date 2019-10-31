#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int Head = 0;
	int Tail = 0;
	char Tmp = 0;
	char str[100];

	gets(str);
	Tail = strlen(str) - 1;
	while (Head < Tail)
	{
		Tmp = str[Head];
		str[Head] = str[Tail];
		str[Tail] = Tmp;
		Head++;
		Tail--;
	}
	puts(str);

	return 0;
}
