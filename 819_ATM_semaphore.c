#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

sem_t sem_ATM;

void *pthread_ATM(void *arg)
{
	while (1)
	{
		sem_wait(&sem_ATM);
		printf("%lu[%d] Enter The ATM\n", pthread_self(), *(int *)arg);
		sleep(rand()%10 +1);
		printf("\t%lu[%d] Leave The ATM\n", pthread_self(), *(int *)arg);
		sem_post(&sem_ATM);
		break;
	}

	return NULL;
}


int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
	pthread_t ptid[10];
	int id[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	sem_init(&sem_ATM, 0, 3);
	
	srand(time(NULL));
	
	for (i = 0; i < 10; i++)
	{
		pthread_create(&ptid[i], NULL, pthread_ATM, &id[i]);
	}
	for (i = 0; i < 10; i++)
	{
		pthread_join(ptid[i], NULL);
	}

	sem_destroy(&sem_ATM);


	return 0;
}
