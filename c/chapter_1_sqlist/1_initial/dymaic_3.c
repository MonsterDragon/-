#include<stdio.h>
#include<stdlib.h>

#define InitLength 12

typedef struct
{
	int *data;
	int length;
	int MaxSize;
}SqList;

void InitList(SqList *L)
{
	L -> MaxSize = InitLength;
	L -> data = (int *)malloc(L -> MaxSize * sizeof(int));
	L -> length = 0;
}

void IncreaseList(SqList *L, int l)
{
	int i;
	int *q = L -> data;
	L -> MaxSize = L -> MaxSize + l;
	L -> data = (int *)malloc(L -> MaxSize * sizeof(int));
	for (i = 0; i < L -> length; i++)
	{
		L -> data[i] = q[i];
	}
	free(q);
}

int main()
{
	int i;
	SqList L;
	InitList(&L);
	for (i = 0; i < L.MaxSize; i++)
	{
		L.data[i] = i;
	}
	L.length = InitLength;
	IncreaseList(&L, 5);
	for (i = 0; i < L.MaxSize; i++)
	{
		printf("data[%d] : %d\n", i, L.data[i]);
	}
}
