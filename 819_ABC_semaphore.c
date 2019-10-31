#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t sem_A;
sem_t sem_B;
sem_t sem_C;


void *pthread_A(void *arg)
{
	while (1)
	{
		sem_wait(&sem_A);
		putchar('A');
		sem_post(&sem_B);
	}

	return NULL;
}
void *pthread_B(void *arg)
{
	while (1)
	{
		sem_wait(&sem_B);
		putchar('B');
		sem_post(&sem_C);
	}

	return NULL;
}
void *pthread_C(void *arg)
{
	while (1)
	{
		sem_wait(&sem_C);
		putchar('C');
		putchar('\n');
		sem_post(&sem_A);
	}

	return NULL;
}


int main(int argc, const char *argv[])
{
	int i = 0;
	int ret  = 0;
	pthread_t ptid[3];
	void *(*pthread_p[])(void *) = {
		pthread_A,
		pthread_B,
		pthread_C
	};

	sem_init(&sem_A, 0, 1);
	sem_init(&sem_B, 0, 0);
	sem_init(&sem_C, 0, 0);
	for (i = 0; i < 3; i++)
	{
		pthread_create(&ptid[i], NULL, pthread_p[i], NULL);
	}
	for (i = 0; i < 3; i++)
	{
		pthread_join(ptid[i], NULL);
	}
	sem_destroy(&sem_A);
	sem_destroy(&sem_B);
	sem_destroy(&sem_C);




	return 0;
}
