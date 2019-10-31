#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, const char *argv[])
{
	int i = 0;
	int fdsrc = 0;
	int fddest = 0;
	char Tmp[2] = {0};
	int ret = 0;

	if (3 != argc)
	{
		fprintf(stderr, "Usage: ./Cp.out srcfilename destfilename\n");
		return -1;
	}
	fdsrc = open(argv[1], O_RDONLY);
	if (-1 == fdsrc)
	{
		perror("fail to src open");
		return -1;
	}
	fddest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (-1 == fddest)
	{
		perror("fail to dest open");
		return -1;
	}

	while (ret = read(fdsrc, Tmp, sizeof(Tmp)))
	{
		write(fddest, Tmp, ret);
	}

	close(fdsrc);
	close(fddest);

	return 0;
}
