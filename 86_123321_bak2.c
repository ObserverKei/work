#include <stdio.h>

#define IN
#define OUT
#define INOUT

int If12321(IN int Num);


/*************************************************
 * 	函数名：If12321
 * 	功  能：判断是否是回文数
 * 	参  数：int Num 数字
 *	返回值：
 *		是则返回	1
 *		否则返回	0
*************************************************/
int If12321(IN int Num)
{
	int i = 0;
	int Cnt = 0;
	int ReNum = 0;
	int SaveNum = 0;

	SaveNum = Num;
	while (Num)
	{
		ReNum = ReNum*10 + Num%10;
		Num /= 10;
	}

	if (SaveNum == ReNum)
	{
		return 1;
	}

	return 0;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;

	puts("please input Number:");
	scanf("%d", &i);
	if (If12321(i))
	{
		puts("is");
	}
	else
	{
		puts("not");
	}
	
	return 0;
}
