#include <stdio.h>

#define IN
#define	OUT 
#define INOUT

void *memcpy(IN void *dest, IN const void *src, int n);

/***********************************************************
 * 	函数名：memcpy
 * 	功  能：拷贝指定长度的空间
 * 	参  数：
 * 		void *dest 			目标地址
 * 		const void *src		源地址
 * 		int	n				指定长度
 *	返回值：
 *		成功返回	目标地址
 *		失败返回	NULL
***********************************************************/
void *memcpy(IN void *dest, IN const void *src, int n)
{
	char *Tmpdest = NULL;
	char *Tmpsrc = NULL;
	int i = 0; 
	
	Tmpdest = (char *)dest;
	Tmpsrc = (char *)src;
	if (NULL == dest || src == NULL)
	{
		return NULL;
	}

	while (i < n)
	{
		Tmpdest = Tmpsrc;
		Tmpdest++;
		Tmpsrc++;
		i++;
	}

	return dest;
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int j = 100;

	memcpy(&i, &j, 4);
	printf("i = %d\n", i);
	return 0;
}
