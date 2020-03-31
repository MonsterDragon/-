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
	for (i = 0; i < MaxSize; i++)
	{
		L -> data[i] = 0;
	}
	L -> length = 0;
}

bool SubtractList(SqList *L, int i, int *n)
{
	if (L -> length > MaxSize)
	{
		return false;
	}
	else if (i < 1 || i > L -> length)
	{
		return false;
	}
	else
	{
		int num;
		*n = L -> data[i - 1];
		for (num = i - 1; num < L -> length; num++ )
		{
			L -> data[num] = L -> data[num + 1];
		}
		return true;
	}	
}

int main()
{
	int i;
	bool result;
	int e = 0;
	SqList L;
	InitList(&L);
	for (i = 0; i < MaxSize -2; i++)
	{
		L.data[i] = i + 2;
	}
	L.length = MaxSize - 2;
	result = SubtractList(&L, 3, &e);
	if (result)
	{
		printf("Execute is successful, delete element is %d\n", e);
	}
	else
	{
		printf("Execute is failed\n");
	}
	for (i = 0; i < MaxSize; i++)
	{
		printf("data[%d] = %d\n", i, L.data[i]);
	}
}
