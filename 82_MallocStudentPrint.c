#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN
#define OUT
#define INOUT

struct student 
{
	char name[32];
	char sex;
	int age;
	int score;
};

struct student *GetStuInfo(INOUT struct student **pclass, IN int len);
void PRINTstuInfo(IN struct student src);


struct student *GetStuInfo(INOUT struct student **pclass, IN int len)
{
	int i = 0;

	do {
		printf("请输入第%d名学生的姓名：\n", i+1);
		scanf(" %s", (*pclass)[i].name);
		printf("请输入第%d名学生的性别：\n", i+1);
		scanf(" %c", &(*pclass)[i].sex);
		printf("请输入第%d名学生的年龄：\n", i+1);
		scanf(" %d", &(*pclass)[i].age);
		printf("请输入第%d名学生的分数：\n", i+1);
		scanf(" %d", &(*pclass)[i].score);
		i++;
	} while (i < len);
	
	i = 0;
	while (i < len)
	{
		printf("===第%d名学生===\n", i+1);
		PRINTstuInfo((*pclass)[i]);
		i++;
	}

	return *pclass;
}

void PRINTstuInfo(struct student src)
{
	printf(" name:\t%s\n", src.name);
	printf("  sex:\t%c\n", src.sex);
	printf("  age:\t%d\n", src.age);
	printf("score:\t%d\n", src.score);

	return;
}


int main(int argc, const char *argv[])
{
	int i = 0;

	struct student *pclass[5] = {NULL};

	pclass[0] = (struct student *)malloc(sizeof(struct student)*5);

	if (NULL == pclass[0])
	{
		puts("fail to malloc");
		return -1;
	}
	memset(*pclass, 0, (44*5));

	GetStuInfo(pclass, 3);

	free(*pclass);

	return 0;
}
