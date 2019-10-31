#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define IN
#define	OUT 
#define INOUT

#define NAME_LEN 32

sem_t sem_desk;
pthread_mutex_t lock;

typedef struct ListNode
{
	int id;
	int stat;
	pthread_t ptid;
	char name[NAME_LEN];
	struct ListNode *pNext;
}ListNode_S;

typedef struct Pthread
{
	pthread_t ptid;
	void *(*func)(void *);
	int flag;
}PthreadList_S;

void Init(void);
void *Desk(void *arg);
void *Water(void *arg);
void *InputNode(void *arg);
ListNode_S *CreatNode(void);
void *PRINTListNode(void *arg);
void InsertNode(ListNode_S *pNode);


ListNode_S *pHead = NULL;
ListNode_S *pPreHead = NULL;
int ListNode_Len = 0;

PthreadList_S PthreadList[] = {
	{0, InputNode, 1},
	{0, Water, 1},
	{0, Desk, 3},

//	{0, PRINTListNode, 1},
};
int PthreadList_Len = sizeof(PthreadList) / sizeof(PthreadList[0]);
int ListNode_History = 0;

	int i = 3;

ListNode_S *CreatNode(void)
{
	ListNode_S *pNode = NULL;

	pNode = (ListNode_S *)malloc(sizeof(ListNode_S));
	if (NULL == pNode)
	{
		perror("fail to malloc");
		return NULL;
	}
	memset(pNode, 0, sizeof(ListNode_S));

	pNode->pNext = NULL;

	return pNode;
}

void Init(void)
{
	int i = 0;
	sem_init(&sem_desk, 0, 3);
	pthread_mutex_init(&lock, NULL);
	
	pHead = CreatNode();
	pPreHead = CreatNode();
	pPreHead->pNext = pHead;
	/* pthread init */
	for (i = 0; i < PthreadList_Len; i++)
	{
		pthread_create(&PthreadList[i].ptid, NULL, PthreadList[i].func, NULL);
	}

	return;
}
void *InputNode(void *arg)
{
	char TmpStr[NAME_LEN] = {0};
	ListNode_S *pNode = NULL;
	pNode = CreatNode();
	

	while(1)
	{
		gets(TmpStr);
		if (strncmp(TmpStr, " ", strlen(" ")) && strcmp(TmpStr, ""))
		{
			pNode = CreatNode();
			strcpy(pNode->name, TmpStr);
			InsertNode(pNode);	
			PRINTListNode(NULL);
		}
	}

	return 0;
}

void InsertNode(ListNode_S *pNode)
{
	ListNode_S *pTmp = NULL;
	pTmp = pHead;
	
	while (NULL != pTmp->pNext)
	{
		pTmp = pTmp->pNext;
	}
	pTmp->pNext = pNode;
	
	ListNode_History++;
	pNode->id = ListNode_History;

	return;
}

void Recovery(void)
{
	int i = 0;
	for (i = 0; i < PthreadList_Len; i++)
	{
		pthread_join(PthreadList[i].ptid, NULL);
	}
	
	pthread_mutex_destroy(&lock);
	sem_destroy(&sem_desk);

	return;
}

void *PRINTListNode(void *arg)
{
	ListNode_S *pTmp = NULL;

	pTmp = pHead->pNext;
	
	printf("===========\n");
	while (NULL != pTmp)
	{
		if ( ! pTmp->stat)
		{
			printf("id:%d\t%s\n", pTmp->id, pTmp->name);
		}
		pTmp = pTmp->pNext;
	}
	printf("===========\n");

	pTmp = pHead->pNext;
	while (NULL != pTmp)
	{
		if (pTmp->stat)
		{
			printf("\tid:%d\t%s\t正在用餐\n", pTmp->id, pTmp->name);
			
		}
		pTmp = pTmp->pNext;
	}
	return NULL;
}

void *Desk(void *arg)
{
	printf("0=餐桌======0=====\n");
	if (NULL == arg)
	{
		return NULL;
	}


	srand(time(NULL));
	ListNode_S *pTmpPreNode = (ListNode_S *)arg;
	ListNode_S *pTmpNode = pTmpPreNode->pNext;
	ListNode_S LoseNode;
	LoseNode = *pTmpNode;
	pTmpNode->stat = 1;
	PRINTListNode(NULL);
	sleep(5);
	pTmpPreNode->pNext = pTmpNode->pNext;	


	printf("\tid:%d\t%s\t离开桌子\n", LoseNode.id, LoseNode.name);
	PRINTListNode(NULL);
	

	sem_post(&sem_desk);
		
	return NULL;	
}

void *Water(void *arg)
{
	ListNode_S *pSaveNode = NULL;
	ListNode_S *pPrePreNode = NULL;
	ListNode_S *pPreNode = NULL;
	ListNode_S *pTmpNode = NULL;
#if 1	

	pTmpNode = pHead;
	pPreNode = pHead;
	pPrePreNode = pPreHead;
	while (1)
	{
		sleep(1);
		sem_wait(&sem_desk);		
		if (NULL != pHead->pNext && pTmpNode->pNext != NULL)
		{
			pPrePreNode = pPrePreNode->pNext;
			pPreNode = pPreNode->pNext;
			pTmpNode = pTmpNode->pNext;

			printf("%d %s start in desk\n", pPreNode->id, pPreNode->name);
			pPreNode->stat = 1;
			sleep(5);
			pPrePreNode->pNext = pPreNode->pNext;
			printf("%d %s leave desk\n", pPreNode->id, pPreNode->name);

			sem_post(&sem_desk);
		}
		else
		{
			pthread_mutex_unlock(&lock);
			sem_post(&sem_desk);
		}
	}
#endif
	return NULL;
}

int main(int argc, const char *argv[])
{

	Init();
	Recovery();

	return 0;
}
