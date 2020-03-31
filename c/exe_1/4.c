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
	L -> length = 0;
	L -> MaxSize = InitSize;
	int i;
	for (i = 0; i < L -> MaxSize; i++)
	{
		L -> data[i] = 0;
	}
}

bool DeleteEles(SqList *L, int s, int t)
{
	if (s >= t || L -> length == 0)
		return false;
	int i, j;
	for (i = 0; i < L -> length; i++)
	{
		if (L -> data[i] > s)
			break;
	}
	if (i > L -> length)
	{
		return false;
	}
	for (j = i; i < L -> length; j++)
	{
		if (L -> data[j] > t)
			break;
	}
	for (; j < L ->length; j++, i++)
	{
		L -> data[i] = L -> data[j];
	}
	L -> length = i;
	return true;
}

int main()
{
	int i;
	bool result;
	SqList L;
	InitList(&L);
	for (i = 0; i < L.MaxSize - 2; i++)
	{
		L.data[i] = i + 2;
	}
	L.length = L.MaxSize -2;
	for (i = 0; i < L.length; i++)
	{
		printf("data[%d] : %d\n", i, L.data[i]);
	}
	result = DeleteEles(&L, 3, 8);
	if (result)
	{
		for (i = 0; i < L.length; i++)
		{
			printf("\ndata[%d] : %d\n", i, L.data[i]);
		}
	}
}
