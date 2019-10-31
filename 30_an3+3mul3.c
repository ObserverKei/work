#include <stdio.h>
#define IN
#define	OUT 
#define INOUT

int obs[100] = {
	0
};
int i_obs = 0;

int FUNCan(IN int a, IN int n);

int FUNCan(int a, int n)
{
	int i = 0;
	int Tmp = 0;
	
	if(1 == n)
	{
//		printf("%d", a);	
		obs[i_obs++] = a;
		return a;
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			Tmp = Tmp * 10 + a;
		}
//		printf("%d+", Tmp);	
		obs[i_obs++] = Tmp;
		return FUNCan(a, n-1) + Tmp;
	}
	return 0;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int a = 0;
	int n = 0;
	int Ret = 0;

	puts("请输入a和n：");
	scanf("%d%d", &a, &n);

	Ret = FUNCan(a, n);

	while (i_obs)
	{
		printf("%d+", obs[--i_obs]);
	}
	printf("%d=%d。\n", obs[0], Ret);


	return 0;
}
