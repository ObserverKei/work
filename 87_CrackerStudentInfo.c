#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN
#define OUT
#define INOUT

typedef struct stu
{
	char name[32];
	char sex;
	int age;
	int score;
	struct stu *pNext;
}NoteStudent;


NoteStudent *CreateStu(void);
NoteStudent *CreateLinkListStu(IN int n);
void PRINTstu(IN NoteStudent *pTmpStu);
NoteStudent *CrackerStuInfo(INOUT NoteStudent *pStuHead, IN char *str);

/********************************************
 * 	函数名:	CreateStu
 * 	功  能:	创建学生信息节点
 * 	传  参:	无
 * 	返回值:
 * 		成功返回	节点地址
 * 		失败返回	NULL
********************************************/
NoteStudent *CreateStu(void)
{
	NoteStudent *pStu = NULL;

	pStu = malloc(sizeof(NoteStudent));
	if (NULL == pStu)
	{
		perror("fail to malloc");
		return NULL;
	}
	memset(pStu, 0, sizeof(NoteStudent));
	pStu->pNext = NULL;

	return pStu;
}

/********************************************
 * 	函数名:	CreateLinkListStu
 * 	功  能:	创建学生信息链表
 * 	传  参:	int n	学生数量
 * 	返回值:
 * 		成功返回	链表地址
 * 		失败返回	NULL
********************************************/
NoteStudent *CreateLinkListStu(IN int n)
{
	NoteStudent *pHead = NULL;
	NoteStudent *pTmpNote = NULL;
	
	if (n < 1)
	{
		perror("fail to malloc");
		return NULL;
	}

	pHead = CreateStu();
	while (n)
	{
		pTmpNote = CreateStu();
		pTmpNote->pNext = pHead->pNext;
		pHead->pNext = pTmpNote;
		n--;
	}
	
	return pHead;
}

/********************************************
 * 	函数名:	PRINTstu	
 * 	功  能:	打印学生信息
 * 	传  参: NoteStudent TmpStu	学生节点	
 * 	返回值: void
********************************************/
void PRINTstu(IN NoteStudent *pTmpStu)
{
	printf(" name:\t%s\n", pTmpStu->name);
	printf("  sex:\t%c\n", pTmpStu->sex);
	printf("  age:\t%d\n", pTmpStu->age);
	printf("score:\t%d\n", pTmpStu->score);

	return;
}

/********************************************
 * 	函数名:	CrackerStuInfo	
 * 	功  能:	解码字符串中信息往链表中添加
 * 	传  参:	
 * 		NoteStudent *pStuHead	学生链表头
 * 		char *str				需要解码的字符串
 * 	返回值:	
 * 		写入成功的学生链表地址
********************************************/
NoteStudent *CrackerStuInfo(INOUT NoteStudent *pStuHead, IN char *str)
{
	char *pTmpStrHead = NULL;
	char *pTmpStr = NULL;
	NoteStudent *pTmpNote = NULL;
	int Cnt = 0;
	int Tmp = 0;
	int i = 0;

	pTmpNote = CreateStu();
	pTmpStrHead = str;
	while ('\0' != *str)
	{
		if (';' == *str && 0 == Cnt)
		{
			while(pTmpStrHead < str)
			{
				pTmpNote->name[i++] = *pTmpStrHead;
				pTmpStrHead++;
			}
			pTmpNote->name[i] = '\0';
			Cnt++;
			pTmpStrHead++;
			str++;
		}
		if (';' == *str && 1 == Cnt)
		{
			pTmpNote->sex = *pTmpStrHead;
			Cnt++;
			pTmpStrHead += 2;
			str++;
		}
		if (';' == *str && 2 == Cnt)
		{
			while (pTmpStrHead < str)
			{
				pTmpNote->age = pTmpNote->age * 10 + *pTmpStrHead - '0';
				pTmpStrHead++;
			}
			Cnt++;
			pTmpStrHead++;
			str++;
		}
		str++;
	}
	while(3 == Cnt && pTmpStrHead < str)
	{
		pTmpNote->score = pTmpNote->score * 10 + *pTmpStrHead - '0';
		pTmpStrHead++;
	}
	pTmpNote->pNext = pStuHead->pNext;
	pStuHead->pNext = pTmpNote;

	return pTmpNote;
}
int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	int n = 0;
	char str[100] = {"qlno;f;12;45"};
	NoteStudent *pHead = NULL;
	NoteStudent *pTmpNote = NULL;

	puts("请输入需要记录的学生数量：");
	scanf("%d", &n);
	getchar();
	pHead = CreateStu();
	if (n > 0)
	{
		while (i < n)
		{
			puts("请输入需要记录的学生信息：");
			gets(str);
			printf("=====第%d名学生=====\n", i+1);
			PRINTstu(CrackerStuInfo(pHead, str));
			i++;
		}

		i = 0;
		pTmpNote = pHead->pNext;
		while(i < n)
		{
			puts("记录的学生信息：");
			printf("====================\n");
			PRINTstu(pTmpNote);
			pTmpNote = pTmpNote->pNext;
			i++;
		}
	}
	else
	{
		puts("please check your input!");
	}
	
	return 0;
}
