#include<stdio.h>
#include<stdlib.h>

#define InitSize 12

typedef struct
{
	int *data;
	int length;
	int MaxSize;
}SqList;

void InitList(SqList *L)
{
	L -> data = (int *)malloc(InitSize * sizeof(int));
	L -> length = 0;
	L -> MaxSize = InitSize;
}

void IncreaseList(SqList *L, int len)
{
	int i;
	int *q = L -> data;
	L -> data = (int *)malloc((L -> MaxSize + len) * sizeof(int));
	for (i = 0; i < L -> length; i++)
	{
		L -> data[i] = q[i];
	}
	L -> MaxSize = L -> MaxSize + len;
	free(q);
}

int main()
{
	int i, len = 5;
	SqList L;
	InitList(&L);
	for (i = 0; i < 5; i++)
	{
		L.data[i] = i;
	}
	L.length = len;
	IncreaseList(&L, len);
	for (i = 0; i < L.MaxSize; i++)
	{
		printf("data[%d] : %d\n", i, L.data[i]);
	}
}
