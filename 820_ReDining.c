#include <stdio.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define FLAG_OFF 	0	//线程关闭
#define FLAG_ON		1	//线程开启

/*	线程结构体	*/
typedef struct pthread
{
	pthread_t ptid;
	void *(*pthread_main)(void *);
	int flag;
}PTHREAD_LIST_S;

/*	队列	*/
typedef struct queue
{
	int id;
	char name[32];
	struct queue *(*func_tail)(struct queue *);
	struct queue *pNext;
}QUEUE_S;

void DiningInit(void);
void DiningDestroy(void);
void *TableMainThread(void *arg);
void *WaterMainThread(void *arg);
QUEUE_S *CreatQueueNode(void);
QUEUE_S *QueueTailInser(QUEUE_S *pHead);

/*	线程列表	*/
PTHREAD_LIST_S PthreadDining_list[] = {
	{0, WaterMainThread, FLAG_ON},
};

QUEUE_S *pHead = NULL;		//队列头

sem_t sem_table;			//桌子人数锁限制
pthread_mutex_t	lock;		//原子操作锁

/*	创建队列节点 */
QUEUE_S *CreatQueueNode(void)
{
	QUEUE_S *pTmp = NULL;

	pTmp = malloc(sizeof(QUEUE_S));
	if (NULL == pTmp)
	{
		perror("fail to malloc");
		return NULL;
	}
	memset(pTmp, 0, sizeof(QUEUE_S));

	pTmp->pNext = NULL;
	pTmp->func_tail = QueueTailInser;

	return pTmp;
}

/*	尾部节点 */
QUEUE_S *QueueTailInser(QUEUE_S *pHead)
{
	QUEUE_S *pTmpNode = NULL;

	pTmpNode = pHead;
	while (NULL != pTmpNode->pNext)
	{
		pTmpNode = pTmpNode->pNext;
	}

	return pTmpNode;
}

/*	服务员	*/
void *WaterMainThread(void *arg)
{
	pthread_t ptid;

	while (1)
	{
		sem_wait(&sem_table);
		pthread_mutex_lock(&lock);
		if (NULL != pHead->pNext)
		{
			pthread_create(&ptid, NULL, TableMainThread, pHead->pNext);
			pHead->pNext = pHead->pNext->pNext;
			pthread_mutex_unlock(&lock);
		}
		else
		{
			pthread_mutex_unlock(&lock);
			sem_post(&sem_table);
		}
	}

	return NULL;
}

/*	餐桌	*/
void *TableMainThread(void *arg)
{
	QUEUE_S *pTmpNode = (QUEUE_S *)arg;

	srand(time(NULL));
	
	printf("[%d]%s开始吃饭\n", pTmpNode->id, pTmpNode->name);
	sleep(rand()%10 + 1);
	printf("[%d]%s走了\n", pTmpNode->id, pTmpNode->name);
	
	/*	销毁节点	*/
	
	free(pTmpNode);
	sem_post(&sem_table);
	
	return NULL;
}

void DiningInit(void)
{
	int i = 0;
	

	pHead = CreatQueueNode();
	
	sem_init(&sem_table, 0, 3);
	
	pthread_mutex_init(&lock, NULL);

	for (i = 0; i < sizeof(PthreadDining_list) / sizeof(PthreadDining_list[0]); i++)
	{
		pthread_create(&PthreadDining_list[i].ptid, NULL, PthreadDining_list[i].pthread_main, &PthreadDining_list[i]);
	}

	return;
}

void DiningDestroy(void)
{
	
	sem_destroy(&sem_table);
	pthread_mutex_destroy(&lock);

	return;
}

int main(int argc, const char *argv[])
{
	int Cnt = 0;
	QUEUE_S *pTmp = NULL;

	DiningInit();

	while (1)
	{
		pTmp = CreatQueueNode();
		Cnt++;
		pTmp->id = Cnt;
		
		gets(pTmp->name);
	
		pHead->func_tail(pHead)->pNext = pTmp;
	}
	
	DiningDestroy();

	return 0;
}
