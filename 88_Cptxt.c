#include <stdio.h>

//ASCII only
int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 0;
	char c = 0;
	FILE *fpsrc = NULL;
	FILE *fpdest = NULL;

	if (3 != argc)
	{
		printf("Uage: ./Cptxt.out SrcFileName1.txt DestFileName2.txt\n");
//		fprintf(stderr, "Uage: ./Cptxt.out SrcFileName1.txt DestFileName2.txt\")
//		向着出错流打印信息，这样即使没有满足终端开启的三个流中其中
//		一个的stdout流的刷新条件五分之一的 \n 也可已快速刷新
		return -1;
	}
	
	fpsrc = fopen(argv[1], "r");
	if (NULL == fpsrc)
	{
		perror("fail to src fopen");
	}
	fpdest = fopen(argv[2], "w");
	if (NULL == fpdest)
	{
		perror("fail to dest fopen");
	}
	
	while (EOF != (c = fgetc(fpsrc)))
	{
		fputc(c, fpdest);
	}


	fclose(fpsrc);
	fclose(fpdest);

	return 0;
}
