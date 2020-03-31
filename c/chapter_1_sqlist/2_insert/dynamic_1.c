#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define InitSize 12

typedef struct
{
	int *data;
	int length;
	int MaxSize;
}SqList;

void InitList(SqList *L)
{
	int i;
	L -> MaxSize = InitSize;
	L -> data = (int *)malloc(L -> MaxSize * sizeof(int));
	for (i = 0; i < L -> MaxSize; i++)
	{
		L -> data[i] = 0;
	}
	L -> length = 0;
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
	L -> MaxSize += len;
	free(q);
}

bool InsertList(SqList *L, int i, int n)
{
	int index;
	if (L -> length == L -> MaxSize)
	{
		IncreaseList(L, 10);
	}
	if (i < 1 || i > L -> length + 1)
	{
		printf("%d\n", L -> length);
		return false;
	}
	else 
	{
		for (index = L -> length - 1; index >= i - 1; index--)
		{
			L -> data[index + 1] = L -> data[index];
		}
		L -> data[i - 1] = n;
		L -> length++;
		return true;
	}
}

int main()
{
	int i;
	bool result;
	SqList L;
	InitList(&L);
	for (i = 0; i < L.MaxSize; i++)
	{
		L.data[i] = i + 3;
	}
	L.length = L.MaxSize;
	result = InsertList(&L, 3, 10);
	if (result)
	{
		for (i = 0; i < L.MaxSize; i++)
		{
			printf("data[%d] : %d\n", i, L.data[i]);
		}
	}
	else
	{
		printf("Insert fault!\n");
	}
}
