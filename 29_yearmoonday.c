#include <stdio.h>
#include <string.h>
#include <time.h>	//获取系统时间

#define IN
#define OUT
#define INOUT

int ymd(IN char c);	//获取年月日
int YearLeap(IN int year);
int YearET(IN int year, IN int moon, IN int day);
int YearRTS(IN int year, IN int moon, IN int day);

int main(int argc, const char *argv[])
{
	int year = ymd('y');	//定义年月日
	int moon = ymd('m');
	int day = ymd('d');

	if(1 ==	YearLeap(year))
	{
		puts("今年是闰年");
	}
	else if (0 == YearLeap(year))
	{
		puts("今年不是闰年");
	}
	
	printf("use day = %d\n", YearET(year, moon, day));
	printf("remaining day = %d\n", YearRTS(year, moon, day));

	printf("year = %4d\n", year);
	printf("moon = %4d\n", moon);
	printf(" day = %4d\n", day);
	return 0;
}

int ymd(IN char c)
{
	struct tm *ptm;
	long ts;
	int y,m,d,h,n,s;
	
	ts = time(NULL);
	ptm = localtime(&ts);

	y = ptm -> tm_year + 1900;	//年 
	m = ptm -> tm_mon + 1;		//月 
	d = ptm -> tm_mday;			//日 
	h = ptm -> tm_hour;         //时 
	n = ptm -> tm_min;          //分 
	s = ptm -> tm_sec;          //秒
	if ('y' == c)
	{
		return y;
	}
	if ('m' == c)
	{
		return m;
	}
	if ('d' == c)
	{
		return d;
	}

	return 0;
}

int YearLeap(IN int year)
{
	int i = 0;

	if (0 != year % 100 && 0 == year % 4 || 0 ==  year % 400)
	{	
		return 1;
	}
	else
	{
		return 0;
	}

	return -1;
}

int YearET(IN int year, IN int moon, IN int day)
{
	char y = 'y';
	int big = 31;
	int small = 30;
	int Feb1 = 29;
	int Feb0 = 28;
	int Cnt = 0;
	int i = 0;
	int sum = 0;
	for (i = 1; i < moon; i++)
	{
		//big moon :1 3 5 7 8 10 12
		if (1 == i || 3 == i || 5 == i || 7 == i || 8 == i || 10 == i || 12 == i)
		{
			sum += 31;
		}
		//small moon :4 6 9 11
		else if (4 == i || 6 == i || 9 == i || 11 == i)
		{
			sum += 30;
		}
		else if (2 == i)
		{
			if (1 == YearLeap(year))
			{
				sum += 29;
			}
			else if (0 == YearLeap(year))
			{
				sum += 28;
			}
		}
	}
	sum += day;
	return sum;

	#if 0
	if (1 == YearLeap(year))
	{
		switch(moon)
		{
			case 12:return day + Feb1 + big*6 + small*4;break;
			case 11:return day + Feb1 + big*6 + small*3;break;
			case 10:return day + Feb1 + big*5+ small*3;break;
			case 9:return day + Feb1 + big*5 + small*2;break;
			case 8:return day + Feb1 + big*4 + small*2;break;
			case 7:return day + Feb1 + big*3 + small*2;break;
			case 6:return day + Feb1 + big*3 + small;break;
			case 5:return day + Feb1 + big*2 + small;break;
			case 4:return day + Feb1 + big*2;break;
			case 3:return day + Feb1 + big;break;
			case 2:return day + big;break;
			case 1:return day;break;
			default:
				   puts("月数异常");
				   return 0;
		}
	}
	else if (0 == YearLeap(year))
	{
		switch(moon)
		{
			case 12:return day + Feb0 + big*6 + small*4;break;
			case 11:return day + Feb0 + big*6 + small*3;break;
			case 10:return day + Feb0 + big*5+ small*3;break;
			case 9:return day + Feb0 + big*5 + small*2;break;
			case 8:return day + Feb0 + big*4 + small*2;break;
			case 7:return day + Feb0 + big*3 + small*2;break;
			case 6:return day + Feb0 + big*3 + small;break;
			case 5:return day + Feb0 + big*2 + small;break;
			case 4:return day + Feb0 + big*2;break;
			case 3:return day + Feb0 + big;break;
			case 2:return day + big;break;
			case 1:return day;break;
			default:
				   puts("月数异常");
				   return 0;
		}		
	}
	return 0;
	#endif
	


}
int YearRTS(IN int year, IN int moon, IN int day)
{
	if (1 == YearLeap(year))
	{
		return 366 - YearET(year, moon, day);
	}
	else if (0 == YearLeap(year))
	{
		return 365 - YearET(year, moon, day);
	}
	return 0;
}
