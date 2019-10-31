#include <stdio.h>
#include <string.h>

#define IN	
#define OUT
#define INOUT
#define PRINT(x) do{  \
	printf("%lld\n", x);\
}while(0);

int obs[] = {
	0,
	1,
	2,
	3,
	4
};

struct SrcDst
{
	int *p;
	char src[100];
	long long int dst[100];
	long long int ret[5];
};
struct teststruct
{
	struct SrcDst sd;
	int *p;
	char src[100];
	long long int dst[100];
	long long int ret[5];
};

long long int FineNum(IN char *src, OUT long long int *dst );

long long int FineNum(IN char *src, OUT long long int *dst )
{
	int i = 0;
	int	NumLen = 0;
	long long int Tmp = 0;
	
	for (i = 0; i <= strlen(src); i++)
	{
		if ('0' <= src[i] && src[i] <= '9')
		{
			Tmp = Tmp * 10 + (src[i] - '0');
		}
		else
		{
			if('0' <= src[i-1] && src[i-1] <= '9')
			{	
				dst[NumLen] = Tmp;
				Tmp = 0;
				NumLen++;
			}
		}
	}
	return NumLen;
}

int main(int argc, const char *argv[])
{
	int i = 0;
//	char src[100] = {0};
//	int dst[100] = {0};
	struct SrcDst *pch, ch = {
		.src = {0},
		.dst = {0},
		.ret = {0}
	};
	struct teststruct test = {0};
//	struct SrcDst set0;
	memset(&set0, 0, sizeof(set0));
	struct SrcDst set0 = {0};
	
	for (i = 0; i < 100; i++)
	{
		printf("set0.src[%d] = %c ", i, set0.src[i]);
		if (0 == (i+1) % 9)
		{
			puts("");
		}
	}
	puts("");
	puts("");

	
	for (i = 0; i < 100; i++)
	{
		printf("set0.dst[%d] = %lld ", i, set0.dst[i]);
		if (0 == (i+1) % 9)
		{
			puts("");
		}
	}
	puts("");
	puts("");

	for (i = 0; i < 5; i++)
	{
		printf("set0.ret = %lld\n", set0.ret[i]);
	}
	puts("");

	printf("set0.p = %p\n", set0.p);

	pch = &ch;

//	int Ret = 0;

	gets(pch->src);

	((&ch)->ret)[obs[0]] = FineNum((*pch).src,ch.dst);

	for (i = 0; i < (ch.ret)[obs[0]]; i++)
	{
		printf("dst[%d] = %lld\n", i, (pch->dst)[i]);	
	}

	PRINT((pch->ret)[obs[0]]);
	
	return 0;
}
