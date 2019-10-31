#include <stdio.h>

#define IN
#define OUT
#define INOUT

void PRINTlist(IN void *src);
void *SetArounStu(IN int Len, INOUT void **src);
void *ArounStu(IN void *src);

void *PRINTlist(IN void *src)
{
	int i = 0;
	
	if(src != &src)
	{
		pirntf("src = %p\n", src);
		src = **src;
	}

	return src;
}

void *SetArounStu(IN int Len, INOUT void **src)
{
	int i = 0;
	
	for (i = 0; i < Len; i++)
	{
		src[i] = &src[i+1];
	}
	i--;
	src[i] = &src[0];
	
	return src[0];

}

void *ArounStu(IN void *src)
{
	int i = 0;
	int Tmp = 0;
	int Cnt = 0;
	void *TmpHead = NULL;
	void *TmpTail = NULL;

	printf("==%p\n", src);
	if (src == &src)	
	{
		return src;
	}
	src = (src);	 
	
	return ;	  
}


int main(int argc, const char *argv[])
{
	int i = 0;
	void *vp[100] = {NULL};
	void *ret = NULL;
	printf("vp[0] = %p\n", &vp[0]);
	SetArounStu(13, vp);
	
	PRINTlist(13, vp);

	ArounStu(vp[0]);

	printf("ret &src = %p\n", ret);

	printf("ret &src = %d\n", (int)ret - (int)vp[0]);
	return 0;

}
