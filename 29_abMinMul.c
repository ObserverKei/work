#include <stdio.h>
#define IN
#define OUT
#define INOUT


//int Min(IN int x, IN int y);	//一个条件运算符就能解决，就不需要函数
int MulMin(IN int x, IN int y);
int SuvMin(IN int x, IN int y);

int main(int argc, const char *argv[])
{
	int a = 0;
	int b = 0;

	scanf("%d%d", &a, &b);
	
	printf("a & b LCM = %d\n", MulMin(a, b));
	printf("a & b GCD = %d\n", SuvMin(a, b));

	return 0;
}

#if 0
int Min(IN int x, IN int y)
{
	if (x > y)
	{
		return y;
	}
	else if (x < y)
	{
		return x;
	}
	else if (x == y)
	{
		return x;
	}
	
	return 0;

}
#endif

int MulMin(IN int x, IN int y)
{
	return x * y / SuvMin(x, y);
}

int SuvMin(IN int x, IN int y)
{
	int i = 1;	//这里需要注意，0不可用当被除数。

//	int min = Min(x, y);	//这里写麻烦了
	int min = x < y ? x : y;
	int d[100] = {1};
	int j = 1;

	while (i <= min)
	{
		if(0 == x%i && 0 == y%i)	// 寻找公约数
		{
			d[j] = i;
			j++;
		}
		i++;
	}

	return d[j-1];
}
