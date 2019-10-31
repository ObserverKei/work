#include <stdio.h>
#include <string.h>

#define IN
#define OUT	
#define INOUT

int If123321(IN int Num);

/***********************************************
 *	函数名：If123321
 *	功  能：判断是否是回文数
 *	传  参：int Num 数
 *	返回值：
 *		是则返回	 1
 *		否则返回	 0
***********************************************/
int If123321(IN int Num)
{
	int i = 0;
	char str[100] = {0};
	int Div = 0;
	int Cnt = 0;

	if (0 == Num % 10)
	{
		return 0;
	}
	
	Div	= Num;
	while (Div)
	{
		str[i] = Div%10 + '0';
		i++;
		Div /= 10;
	}
	str[i] = '\0';
	
	for (i = 0, Cnt = 0; i < strlen(str)/2; i++)
	{
		if (str[i] == str[strlen(str)-i-1])
		{
			Cnt++;
		}
	}
	if (Cnt == i)
	{
		return 1;
	}

	return 0;
}
int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	
	puts("请输入一个数字");
	scanf("%d",&i);
	if (If123321(i))
	{
		puts("是回文数");
	}
	else
	{
		puts("不是回文数");
	}
	
	return 0;
}
