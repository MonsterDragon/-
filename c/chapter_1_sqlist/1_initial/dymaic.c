#include<stdio.h>
#include<stdlib.h>
#define InitSize 10

typedef struct
{
	int *data;
	int MaxSize; // 顺序表允许的最大长度
	int length;
}SqList;

void InitList(SqList *L)
{
	L -> data = (int *)malloc(InitSize * sizeof(int));
	L -> length = 0;
	L -> MaxSize = InitSize;
}

void IncreaseSize(SqList *L, int len)
{
	int i;
	int *p = L -> data;
	L -> data = (int *)malloc((L -> MaxSize + len) * sizeof(int));
	for (i = 0; i < L -> length; i++)
	{
		L -> data[i] = p[i];
	}
	L -> MaxSize = L -> MaxSize + len;
	free(p);
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
	L.length = L.MaxSize;
	IncreaseSize(&L, 5);
	for (i = 0; i < L.MaxSize; i++)
	{
		printf("the location data[%d] is %d\n", i, L.data[i]);
	}
	return 0;
}
