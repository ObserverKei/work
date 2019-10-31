#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc, const char *argv[])
{
	int i = 0;
	int Ret = 0;
	printf("parent_pid: %d\n", getpid());

	while (i < 8 && (Ret = fork()) > 0)
	{
		i++;
		printf("parent: child_%d_pid: %d\n", i, Ret);
	}
	if (-1 == Ret)
	{
		perror("fail to fork");
		return -1;
	}
	if (0 == Ret)
	{
		printf("\tchild: pid: %d\n", getpid());
		printf("\tchild: ppid: %d\n", getppid());
	}

	sleep(1);

	return 0;
}
