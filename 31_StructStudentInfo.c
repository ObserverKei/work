#include <stdio.h>

#define IN
#define OUT 
#define INOUT
#define SCORE	5

struct student
{
	char name[32];
	int id;
	int score[SCORE];
};

double CalStudentClassScore(IN int Len, IN struct student *src);
void PRINTstudentInfo(IN struct student src);
int FindFailScore(IN int Len, IN struct student *src);
double CalStudentAvgScore(IN struct student src);
int FindWinScore(IN int Len, IN struct student *src);

double CalStudentClassScore(IN int Len, IN struct student *src)
{
	int i = 0;
	double sum = 0;
	for (i = 0; i < Len; i++)
	{
		sum += src[i].score[i];
	}

	return sum / Len;
}
void PRINTstudentInfo(IN struct student src)
{
	printf("   name:\t%s\n", src.name);
	printf("     id:\t%d\n", src.id);
	printf("score 1:\t%d\n", src.score[0]);
	printf("score 2:\t%d\n", src.score[1]);
	printf("score 3:\t%d\n", src.score[2]);
	printf("score 4:\t%d\n", src.score[3]);
	printf("score 5:\t%d\n", src.score[4]);
	
	return;
}
int FindFailScore(IN int Len, IN struct student *src)
{
	int i = 0;
	int j = 0;
	int Cnt = 0;
	int stu = 0;
	double sum = 0;
	for (i = 0; i < Len; i++)
	{
		for (Cnt = 0, j = 0; j < SCORE; j++)	//Cnt内部含有的附属参数放在计数体部分进行赋值完毕
		{
			if (src[i].score[j] < 60)
			{
				Cnt++;
				stu++;
			}
		}
		if (Cnt > 2)
		{
			puts("两门以上不及格课程学生：");
			PRINTstudentInfo(src[i]);
			for (j = 0; j < SCORE; j++)
			{
				sum += src[i].score[j];
			}
			printf("average = %.2lf\n\n", sum / Len);
			sum = 0;
			//Cnt = 0;	//隐含逻辑错误，会在上一名学生只有1门课程被选中的时候出问题。
		}
		
	}

	return stu;
}
double CalStudentAvgScore(IN struct student src)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	
	for (i = 0; i < SCORE; i++)
	{
		sum += src.score[i];
	}
	return sum / 5.0;
}

int FindWinScore(IN int Len, IN struct student *src)
{
	int i = 0;
	int j = 0;
	int Cnt = 0;
	int sor = 0;
	
	for (i = 0; i < Len; i++)
	{
		if (CalStudentAvgScore(src[i]) > 90)
		{
			puts("平均分超过90分的学生：");
			PRINTstudentInfo(src[i]);
		}
		for (Cnt = 0,j = 0; j < SCORE; j++)	//内部含有的附属信息应该注意清零条件。
		{
			if (src[i].score[j] > 85)
			{
				Cnt++;
			}
		}
		if (5 == Cnt)
		{
			puts("全部课程成绩在85分以上的学生：");
			PRINTstudentInfo(src[i]);
			//Cnt = 0;
		}
		#if 0
		for (j = 0; j < SCORE; j++)
		{
			if (src[i].score[j] > 85)
			{
				Cnt++;
			}
		}
		if (5 == Cnt)
		{
			puts("全部课程成绩在85分以上的学生：");
			PRINTstudentInfo(src[i]);
			Cnt = 0; 	//清零条件逻辑错误，应该吧Cnt放在每个历遍的学生前面开始计数。
		}
		#endif
	}

	return 0;
}



int main(int argc, const char *argv[])
{
	double ave = 0;
	struct student class[35] = {
		{"nico", 1, {91, 92, 94, 95, 97}},
		{"bika", 2, {75, 59, 54, 92, 43}},
		{"domo", 3, {85, 88, 87, 89, 82}},
		{"qlno", 4, {65, 30, 55, 22, 69}}
	};
//	struct student class[35] = {	//	这下面的也可以
//		{"nico", 1, 91, 92, 94, 95, 97},
//		{"bika", 2, 75, 59, 54, 92, 43},
//		{"domo", 3, 85, 88, 87, 89, 82},
//		{"qlno", 4, 65, 30, 55, 22, 69},
//	};
	
	printf("第一个课程的平均分：%.2lf\n", CalStudentClassScore(4, class));
	
	FindFailScore(4, class);
		
	FindWinScore(4, class);

	return 0;
}
