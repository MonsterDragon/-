#include<stdio.h>
#include<stdbool.h>

#define MaxSize 12

typedef struct
{
	int data[MaxSize];
	int length;
}SqList;

bool InitList(SqList *L)
{
	int i;
	for (i = 0; i < MaxSize; i++)
	{
		L -> data[i] = 0;
	}
	L -> length = 0;
	return true;
}

bool InsertList(SqList *L, int i, int n)
{
	int index;
	if (L -> length == MaxSize)
		return false;
	else if (i < 1 || i > L -> length + 1)
		return false;
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
	for (i = 0; i < MaxSize - 5; i++)
	{
		L.data[i] = i + 3;
	}
	L.length = MaxSize - 5;
	result = InsertList(&L, 3, 1111);
	if (result)
	{
		for (i = 0; i < L.length; i++)
		{
			printf("data[%d] : %d\n", i, L.data[i]);
		}
	}
	else
	{
		printf("Insert false!\n");
	}
}
