#include<stdio.h>
#include<stdbool.h>
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
	int i;
	for (i = 0; i < InitSize; i++)
	{
		L -> data[i] = 0;
	}
	L -> MaxSize = InitSize;
	L -> length = 0;
}

void IncreaseList(SqList *L, int num)
{
	int *q = L -> data;
	L -> data = (int *)malloc((L -> MaxSize + num) * sizeof(int));
	int i;
	for (i = 0; i < L -> length; i++)
	{
		L -> data[i] = q[i];
	}
	L -> MaxSize += num;
	free(q);
}

int main()
{
	SqList L;
	int i;
	bool result;
	InitList(&L);
	for (i = 0; i < L.MaxSize - 3; i++)
	{
		L.data[i] = i + 3;
	}
	L.length = L.MaxSize - 3;
	IncreaseList(&L, 3);
	for (i = 0; i < L.length; i++)
	{
		printf("data[%d] : %d\n", i, L.data[i]);
	}
	printf("MaxSize is %d\n", L.MaxSize);
}
