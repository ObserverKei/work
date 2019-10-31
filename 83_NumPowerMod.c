#include <stdio.h>

#define IN
#define OUT 
#define INOUT

long long int NumPowerMode(IN int Num, IN int Power, IN int Mod);


/*************************************************
*	函数名：NumPowerMode	
*	功  能：对三位数以上的数字幂次方求余
*	原  理：
*		同余定理：
*		（（A mod m）*（B mod m））mod m ==（A*B）mod m
*		示例：
*		 对幂取模如对37的4次方取模
*		 （37*37*37*37）%m
*		  ==(37%m*(37*37*37)%m)%m
*		  ==(37%m*(37%m*(37*37)%m)%m)%m
*		  ==(37%m*(37%m*(37%m*37%m)%m)%m)%m
*	参  数：
*		int Num		底数
*		int Power	次方
*		int Mod		对其求余
*	返回值：
*		成功返回	余数
*************************************************/
long long int NumPowerMode(IN	int Num, IN int Power, IN int Mod)
{
	int i = 0;
	long long int SumMod = 0;
	
	if (1 == Power)
	{
		return Num % Mod;
	}
	else
	{
		SumMod = Num;
		for (i = 1; i < Power; i++)
		{
			SumMod *= Num;
			SumMod %= Mod;
		}
	}

	return SumMod;
}


int main(int argc, const char *argv[])
{
	int i = 0;
	int x = 0;
	int y = 0;
	int m = 0;
	long long int ret = 0;
	puts("please input x ^ y % m :");
	puts("x = ");
	scanf("%d", &x);
	puts("y = ");
	scanf("%d", &y);
	puts("m = ");
	scanf("%d", &m);
	ret = NumPowerMode(x, y, m);
	
	printf("ret = %lld\n", ret);
	return 0;
}
