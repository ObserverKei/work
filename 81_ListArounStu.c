#include <stdio.h>
#include <string.h>

#define IN
#define OUT
#define INOUT

struct LinkList 
{
	struct LinkList *next;
};

struct LinkList *Plink;

int PRINTarounLink(IN struct LinkList (*round)[100]);
int LinkListHeadTail(IN int Len, INOUT struct LinkList (*round)[100]);
struct LinkList *KickNo3Link(INOUT struct LinkList *round);
int OutPutLink(IN struct LinkList *Find, IN struct LinkList (*round)[100]);

/***************************************************
 * 函数名：PRINTarounLink
 * 功  能：打印循环链表成员
 * 参  数：
 * 		struct LinkList (*round)[100] 	链表数组
 * 返回值：
 * 		链表长度
**************************************************/
int PRINTarounLink(IN struct LinkList (*round)[100])
{
	int i = 0;
	struct LinkList *Head = NULL;

	Head = &(*round)[0];
	while (Head != (*round)[i].next)	//打印连环。
	{
		printf("&(*round)[%d] = %p -> (*round)[%d].next = %p\n", i, &(*round)[i], i, (*round)[i].next);
		i++;
	}

	printf("&(*round)[%d] = %p -> (*round)[0].next = %p\n", i, &(*round)[i], (*round)[i].next);

	return i+1; 
}

/***************************************************
 * 函数名：LinkListHeadTail
 * 功  能：生成指定长度循环链表
 * 参  数：
 * 		int Len             			指定长度
 * 		struct LinkList (*round)[100] 	链表数组
 * 返回值：
 * 		成功返回 0
**************************************************/
int LinkListHeadTail(IN int Len, INOUT struct LinkList (*round)[100])
{
	int i = 0;
	struct LinkList Tmp;
	struct LinkList *TmpHead = NULL;

	TmpHead = &(*round)[0];

	do {
		(*round)[i].next = &(*round)[i+1];
		i++;
		
	} while (i < Len-1);	//生成链环。
	(*round)[i].next = TmpHead;

	return 0;
}

/***************************************************
 * 函数名：KickNo3Link
 * 功  能：踢出数到3的人
 * 参  数：
 * 		struct LinkList *round 	链表数组头
 * 返回值：
 * 		最后剩下的人的地址
**************************************************/
struct LinkList *KickNo3Link(INOUT struct LinkList *round)
{
	int i = 0;
	struct LinkList *pTmpNode = NULL;
    struct LinkList *pPreNode = NULL;

	
	pTmpNode = round->next;
	pPreNode = round;
	
	while (pTmpNode != pTmpNode->next)
	{
		if (0 == i % 2)
		{
			pPreNode->next = pTmpNode->next;
			pTmpNode = pTmpNode->next;
		}
		pTmpNode = pTmpNode->next;
		
	if (pTmpNode == pTmpNode->next->next)		
	{
		if (pTmpNode->next == pTmpNode->next->next->next)
		{
			break;
		}
	}

	}

	return pTmpNode->next;
}

/***************************************************
 * 函数名：OutPutLink
 * 功  能：对比地址在链表数组中的相对位置
 * 参  数：
 * 		struct LinkList *Find 			对比的地址
 * 		struct LinkList (*round)[100] 	链表数组
 * 返回值：相对位置
**************************************************/
int OutPutLink(IN struct LinkList *Find, IN struct LinkList (*round)[100])
{
	int i = 0;

	printf("Find = %p\n", Find);
	while (Find != &(*round)[i])
	{
		(*round)[i].next = &(*round)[i+1];
		i++;
	} 	

	return i+1;
}


int main(int argc, const char *argv[])
{
	struct LinkList round[100];
	int ret = 0;

	memset(round, 0, sizeof(struct LinkList)*100);

	LinkListHeadTail(13, &round);	//生成连环。

	printf("打印生成的链环\n");	
	printf("循环链表长度= %d\n", PRINTarounLink(&round));	//链环成员:
	
	puts("打印最后剩下的人的地址:");
	ret = OutPutLink(KickNo3Link(round), &round);
	printf("最后剩下的人相对位置 = %d\n", ret);
	
	return 0;
}
