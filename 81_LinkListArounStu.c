#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN
#define OUT
#define INOUT

typedef int DataType;

typedef struct Node
{
	DataType Data;
	struct Node *pNext;
}LinkNode;

LinkNode *GetLinkNode(void);
int InserHeadLinkList(INOUT LinkNode *pTmpHead, IN DataType TmpData);
int PRINTlinkList(IN LinkNode *pTmpHead);
int InserTailLinkList(INOUT LinkNode *pTmpHead, IN DataType TmpData);
LinkNode *FindLinkNode(IN LinkNode *pTmpHead, IN DataType TmpData);
int ReviseLinkList(INOUT LinkNode *pTmpHead, IN DataType OldTmpData, IN DataType NewTmpData);
int DeleteLinkList(INOUT LinkNode *pTmpHead, IN DataType DelTmpData);
int DestroyLinkList(INOUT LinkNode **pTmpHead);

/************************************
 * 	函数名：GetLinkNode
 * 	功  能：创建一个链表节点
 * 	参  数：无
 * 	返回值：
 * 			成功返回	节点地址
 * 			失败返回	NULL
************************************/
LinkNode *GetLinkNode(void)
{
	LinkNode *pTmpNode = NULL;
	
	pTmpNode = malloc(sizeof(LinkNode));
	if (NULL == pTmpNode)
	{
		puts("fial to malloc");
		return NULL;
	}
	memset(pTmpNode, 0, sizeof(LinkNode));
	
	pTmpNode->Data = 0;
	pTmpNode->pNext = NULL;

	return pTmpNode;
}

/************************************
 * 	函数名：InserHeadLinkList
 * 	功  能：在链表头中插入数据
 * 	参  数：
 * 		LinkNode *pTmpHead 链表头
 * 		DataType TmpData   插入数据
 * 	返回值：
 * 		成功返回	 0
 * 		失败返回	-1
************************************/
int InserHeadLinkList(INOUT LinkNode *pTmpHead, IN DataType TmpData)
{
	LinkNode *pTmpNode = NULL;
	
	pTmpNode = GetLinkNode();
	if (NULL == pTmpNode)
	{
		return -1;
	}

	pTmpNode->pNext = pTmpHead->pNext;
	pTmpHead->pNext = pTmpNode;

	pTmpNode->Data = TmpData;

	return 0;	
}

/************************************
 * 	函数名：PRINTlinkList
 * 	功  能：历遍链表，打印数据
 * 	参  数：LinkNode *pTmpHead 链表头
 * 	返回值：
 * 		成功返回	 0
 * 		失败返回	-1
************************************/
int PRINTlinkList(IN LinkNode *pTmpHead)
{
	LinkNode *pTmpNode = NULL;
	
	pTmpNode = pTmpHead->pNext;
	if (NULL == pTmpNode)
	{
		return -1;
	}

	while (NULL != pTmpNode)
	{
		printf("%d ", pTmpNode->Data);
		pTmpNode = pTmpNode->pNext;
	}
	puts("");

	return 0;
}


/************************************
 * 	函数名：InserTailLinkList
 * 	功  能：往链表尾部插入数据
 * 	参  数：
 * 		LinkNode *pTmpHead 链表头
 *		DataType TmpData   插入数据
 * 	返回值：
 * 		成功返回	 0
 * 		失败返回	-1
************************************/
int InserTailLinkList(INOUT LinkNode *pTmpHead, IN DataType TmpData)
{
	LinkNode *pTmpNode = NULL;
	LinkNode *Node = NULL;

	Node = GetLinkNode();
	if (NULL == Node)
	{
		return -1;
	}
	Node->Data = TmpData;
	Node->pNext = NULL;

	pTmpNode = pTmpHead;
	while (NULL != pTmpNode->pNext)
	{
		pTmpNode = pTmpNode->pNext;
	}
	pTmpNode->pNext = Node;

	return 0;
}

/************************************
 * 	函数名：FindLinkNode
 * 	功  能：寻找匹配传入值的链表成员的地址
 *	参  数：
 *		LinkNode *pTmpHead 链表头
 *		DataType TmpData   匹配数值
 *	返回值：
 *		成功返回	成员地址
 *		失败返回	NULL
************************************/
LinkNode *FindLinkNode(IN LinkNode *pTmpHead, IN DataType TmpData)
{
	LinkNode *pTmpNode= NULL;
	
	pTmpNode = pTmpHead->pNext;
	while (NULL != pTmpNode)
	{
		if (TmpData == pTmpNode->Data)
		{
			return pTmpNode;
		}
		pTmpNode = pTmpNode->pNext;
	}

	return NULL;
}

/************************************
 * 	函数名：ReviseLinkList
 * 	功  能：替换链表中的匹配数字
 * 	参  数：
 * 		LinkNode *pTmpHead  链表头
 * 		DataType OldTmpData 匹配数值
 * 		DataType NewTmpData 替换后数值
 * 	返回值：
 * 		成功返回	 0
 * 		失败返回	-1
************************************/
int ReviseLinkList(INOUT LinkNode *pTmpHead, IN DataType OldTmpData, IN DataType NewTmpData)
{
	LinkNode *pTmpNode = NULL;
	pTmpNode = pTmpHead->pNext;

	if (NULL == FindLinkNode(pTmpHead, OldTmpData))
	{
		return -1;
	}
	while (NULL != (pTmpNode = FindLinkNode(pTmpNode, OldTmpData)))
	{
		pTmpNode->Data = NewTmpData;
	}
	return 0;

}
#if 0	//没有返回没有找到的时候的情况
int ReviseLinkList(INOUT LinkNode *pTmpHead, IN DataType OldTmpData, IN DataType NewTmpData)
{
	LinkNode *pTmpNode = NULL;
	
	pTmpNode = pTmpHead->pNext;
	if (NULL == pTmpNode)
	{
		return -1;
	}
	while (NULL != pTmpNode)
	{
		if (OldTmpData == pTmpNode->Data)
		{
			pTmpNode->Data = NewTmpData;
		}
		pTmpNode = pTmpNode->pNext;
	}
	
	return 0;
}
#endif

/************************************
 * 	函数名：DeleteLinkList
 * 	功  能：删除链表中的匹配数字
 * 	参  数：
 * 		LinkNode *pTmpHead  链表头
 * 		DataType DelTmpData 删除的数值
 * 	返回值：
 * 		成功返回	 0
************************************/
int DeleteLinkList(INOUT LinkNode *pTmpHead, IN DataType DelTmpData)
{
	LinkNode *pTmpNode = NULL;
	LinkNode *pPreNode = NULL;

	pTmpNode = pTmpHead->pNext;
	pPreNode = pTmpHead;
	while (NULL != pTmpNode)
	{
		if (DelTmpData == pTmpNode->Data)
		{	
			pPreNode->pNext = pTmpNode->pNext;
			free(pTmpNode);
			pTmpNode = pPreNode->pNext;		//不能是 pTmpNode = pPreNote; 这是if语句，
		}									//不是if else if条件嵌套语句
		else
		{
			pTmpNode = pTmpNode->pNext;
			pPreNode = pPreNode->pNext;
		}
	}

	return 0;
}

/************************************
 * 	函数名：DestroyLinkList
 * 	功  能：销毁链表
 * 	参  数：
 * 		LinkNode **pTmpHead  链表头取地址
 * 	返回值：
 * 		成功返回	 0
************************************/
int DestroyLinkList(INOUT LinkNode **pTmpHead)
{
	LinkNode *pTmpNode = NULL;
	LinkNode *pPreNode = NULL;

	pTmpNode = *pTmpHead;
	pPreNode = *pTmpHead;
	while (NULL != pTmpNode)
	{
		pTmpNode = pTmpNode->pNext;
		free(pPreNode);
		pPreNode = pTmpNode;
	}
	*pTmpHead = NULL;

	return 0;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int Tmp = 0;

	LinkNode *HeadNode;

	HeadNode = GetLinkNode();
	
	while (i < 5)
	{
		i++;
		InserHeadLinkList(HeadNode, (DataType)i);
	}
	PRINTlinkList(HeadNode);


#if 0	
	i = 0;
	while (i < 5)
	{
		i++;
		InserTailLinkList(HeadNode, (DataType)i);
	}
	PRINTlinkList(HeadNode);

	puts("please input you number");
	scanf(" %d", &i);
	if (NULL != FindLinkNode(HeadNode, (DataType)i))
	{
		printf("find = %d\n", FindLinkNode(HeadNode, (DataType)i)->Data);
	}
	else
	{
		puts("can't find");
	}
	
	puts("please input you revise number");
	scanf(" %d", &i);
	puts("please input you new number");
	scanf(" %d", &Tmp);
	ReviseLinkList(HeadNode, (DataType)i, (DataType)Tmp);
	PRINTlinkList(HeadNode);

	puts("please input you delete number");
	scanf(" %d", &i);
	DeleteLinkList(HeadNode, (DataType)i);
	PRINTlinkList(HeadNode);
	
	DestroyLinkList(&HeadNode);
	printf("%p\n", HeadNode);
#endif
	return 0;
}
