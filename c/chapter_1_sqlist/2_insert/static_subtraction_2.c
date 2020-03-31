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
		printf("data[%d] = %d\n", i, L -> data[i]);
	}
	L -> length = 0;
}

bool SubtractList(SqList *L, int i, int *s)
{
	if (i < 1 || i > L -> length)
	{
		return false;
	}
	int index;
	for(index = i - 1; index < L -> length - 1; index++)
	{
		L -> data[index] = L -> data[index + 1];
	}
	*s = L -> data[i - 1];
	L -> length--;
	return true;
}

int main()
{
	int i;
	bool result;
	int s = 0;
	SqList L;
	InitList(&L);
	for (i = 0; i < MaxSize - 5; i++)
	{
		L.data[i] = i + 2;
	}
	L.length = MaxSize - 5;
	result = SubtractList(&L, 3, &s);
	if (result)
	{
		printf("substract successfully which is %d\n");
		for (i = 0; i < L.length; i++)
		{
			printf("data[%d] : %d\n", i, L.data[i]);
		}
	}
	else
	{
		printf("subtract failed!\n");
	}
}
