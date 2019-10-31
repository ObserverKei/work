#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, const char *argv[])
{
	int fdsend;
	int fdaccept;
	int i = 0;
	int ret = 0;
	char Tmpbuf[1024] = {"miao~"};
	char Tmpbuf2[1024] = {"miao~miao~"};

	if (access("./820_fifo_accept", F_OK))
	{
		ret = mkfifo("./820_fifo_accept", 0664);
		if (-1 == ret)
		{
			perror("fail to mkfifo");
			return -1;
		}
	}
	fdsend = open("./820_fifo_send", O_RDWR);
	if (-1 == fdsend)
	{
		perror("fail to open");
		return -1;
	}
	fdaccept = open("./820_fifo_accept", O_RDWR);
	if (-1 == fdaccept)
	{
		perror("fail to open");
		return -1;
	}
	ret = fork();
	if (-1 == ret)
	{
		perror("fail to fork");
		return -1;
	}
	while(1)
	{
		if (0 == ret)
		{
			read(fdsend, Tmpbuf, sizeof(Tmpbuf));
			printf("send:%s\n", Tmpbuf);
		}
		if (ret > 0)
		{
			gets(Tmpbuf2);
			write(fdaccept, Tmpbuf2, sizeof(Tmpbuf2));
		}
	}

	close(fdaccept);
	close(fdsend);
	sleep(5);

	return 0;
}

