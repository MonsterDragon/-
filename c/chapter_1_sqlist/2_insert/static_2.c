#include<stdio.h>
#include<stdbool.h>

#define MaxSize 12

typedef struct
{
	int data[MaxSize];
	int length;
}SqList;

void InitList(SqList *L)
{
	int i;
	for (i = 0; i < L -> length; i++)
	{
		L -> data[i] = 0;
	}
	L -> length = 0;
}

bool InsertList(SqList *L, int i, int n)
{
	if (L -> length == MaxSize)
		return false;
	if (i < 1 || i > L -> length + 1)
		return false;
	int index;
	for (index = L -> length - 1; index >= i - 1; index--)
	{
		L -> data[index + 1] = L -> data[index];
	}
	L -> data[i - 1] = n;
	L -> length++;
	return true;
}

int main()
{
	int i;
	SqList L;
	InitList(&L);
	for (i = 0; i < MaxSize - 5; i++)
	{
		L.data[i] = i + 3;
	}
	L.length = MaxSize - 5;
	InsertList(&L, 3, 55);
	for (i = 0; i < L.length; i++)
	{
		printf("data[%d] : %d\n", i, L.data[i]);
	}
}
