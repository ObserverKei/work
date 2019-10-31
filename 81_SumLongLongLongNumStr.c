#include <stdio.h>
#include <string.h>

#define NUMLEN 100
#define IN
#define OUT
#define INOUT

char *StrAbcCba(INOUT char *src);
int StrNumAvg(INOUT char *Num1, INOUT char *Num2);
char *SumLongLongLongNumStr(IN const char *Num1, IN const char *Num2, OUT char *Sum);

char *StrAbcCba(INOUT char *src)
{
	int i = 0;
	int Len = strlen(src);
	char Tmp = '\0';

	for (i = 0; i < Len / 2; i++)
	{
		Tmp = src[i];
		src[i] = src[Len-i-1];
		src[Len-i-1] = Tmp;
	}
	return src;
}
int StrNumAvg(INOUT char *Num1, INOUT char *Num2)
{
	int LenNum1 = strlen(Num1);
	int LenNum2 = strlen(Num2);
	int i = 0;

	

	for (i = 0; ('0' <= Num1[i] && Num1[i] <= '9') || ('0' <= Num2[i] && Num2[i] <= '9'); i++)
	{

		if (!('0' <= Num1[i] && Num1[i] <= '9'))
		{
			Num1[i] = '0';
		}
		if (!('0' <= Num2[i] && Num2[i] <= '9'))
		{
			Num2[i] = '0';
		}
	}

	return 0;
}

char *SumLongLongLongNumStr(IN const char *SrcNum1, IN const char *SrcNum2, OUT char *Sum)
{
	int CY = 0;
	int Cnt = 0;
	int Tmp = 0;
	int LenNum1 = strlen(SrcNum1);
	int LenNum2 = strlen(SrcNum2);
	int i = 0;
	char Num1[NUMLEN] = {0};
	char Num2[NUMLEN] = {0};

	strcpy(Num1, SrcNum1);
	strcpy(Num2, SrcNum2);
//	puts(Num1);
//	puts(Num2);

	StrAbcCba(Num1);
	StrAbcCba(Num2);
	StrNumAvg(Num1, Num2);
//	puts(Num1);
//	puts(Num2);
//	printf("%d\n", LenNum1);

	for (i = 0; i < (LenNum1 > LenNum2 ? LenNum1 : LenNum2); i++)	
	{

		Tmp = (Num1[i] - '0') + (Num2[i] - '0');
//		printf("Tmp = %d\n", Tmp);
		if (Tmp + CY - 9 > 0)
		{
			Sum[Cnt] = (Tmp + CY - 9) - 1 + '0';
//			printf("\t\t\tTmp + CY - 9 = %d\n", Tmp + CY -9);
//			printf("Tmp = %d\n", Tmp);
//			printf("CY = %d\n", CY);

			Tmp = 0;
			Cnt++;
			CY = 1;
//			printf("out CY = %d\n", CY);
		}
		else 
		{
			Sum[Cnt] = (Tmp + CY) + '0';
//			printf("\t\t\tTmp + CY     = %d\n", Tmp + CY);
//			printf("Tmp = %d\n", Tmp);
//			printf("CY = %d\n", CY);

			Tmp = 0;
			Cnt++;
			CY = 0;
//			printf("out CY = %d\n", CY);
			
		}
	}
	if (1 == CY)
	{	
		Sum[Cnt] = CY  + '0';
		CY = 0;
		Cnt++;
	}

	Sum[Cnt] = '\0';
	StrAbcCba(Sum);

	return Sum;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	char Num1[NUMLEN] = "12345678901234567890";
	char Num2[NUMLEN] = "1111111111111111111";
	char Sum[NUMLEN] = {0};
	
	puts("eg:");
	puts(Num1);
	puts("+");
	puts(Num2);
	puts("=");
	

	SumLongLongLongNumStr(Num1, Num2, Sum);
	puts(Sum);

	puts("please input two num:");
	gets(Num1);
	gets(Num2);
	
	SumLongLongLongNumStr(Num1, Num2, Sum);
	puts(Sum);

	return 0;
}
