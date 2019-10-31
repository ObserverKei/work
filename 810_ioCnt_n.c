#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, const char *argv[])
{
	int fd = 0;
	int Cnt = 0;
	char Tmp = 0;

	if (2 != argc)
	{
		fprintf(stderr, "Usage: ./a.out filename\n");
		return -1;
	}
	fd = open(argv[1], O_RDONLY);
	if (-1 == fd)
	{
		perror("fail to open");
		return -1;
	}
	while (read(fd, &Tmp, 1))
	{
		if ('\n' == Tmp)
		{
			Cnt++;
		}
	}
	fprintf(stdout, "linege: %d\n", Cnt);
	close(fd);

	return 0;
}
