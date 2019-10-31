#include <stdio.h>

#define IN
#define OUT 
#define INOUT

int PrimeNum(IN int n);
int TwoPrimeNum(IN int n);

int PrimeNum(IN int n)
{
	int i = 0;
	int Cnt = 0;

	for (i = 2; i < n; i++)
	{
		if ( ! (n % i == 0))
		{
			Cnt++;
			if (Cnt == n-2)	//如果是素数
			{
				return 1;
			}
		}
	}

	return 0;
}
int TwoPrimeNum(IN int n)
{
	int i = 0;
	int j = 0;
	int Tmp = 0;
	int Cnt = 0;

	for (Tmp = 2,j = 2; j <= n; j++)
	{
		for (Cnt = 0,i = 2; i < j; i++)
		{
			if ( ! (j % i == 0))
			{
				Cnt++;
				if (Cnt == j-2)	//如果是素数
				{
					if (j > 10)
					{
						if (1 == PrimeNum(j/10%10 + j%10*10))	//如果倒置后还是素数
						{
							printf("Pars of prime Numbers: %d \n", j);
						}
					}
				}
			}
		}
	}

	return 0;
}


int main(int argc, const char *argv[])
{
	int i = 0;

	TwoPrimeNum(100);
//	printf("ret = %d\n", PrimeNum(9));
	return 0;
}
