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
}

bool SubtractList(SqList *L, int i, int *s)
{
	int index;
	if (i < 1 || i > L -> length)
		return false;
	else
	{
		*s = L -> data[i - 1];
		for (index = i; index < L -> length; index++)
		{
			L -> data[index - 1] = L -> data[index];
		}
		L -> length--;
		return true;
	}
}

int main()
{
	int i;
	bool result;
	int e;
	printf("%p\n", &e);
	SqList L;
	InitList(&L);
	printf("the situation of data[11] is %p\n", &L.data[11]);
	printf("the situation of length is %p\n", &L.length);
	for (i = 0; i < MaxSize - 5; i++)
	{
		L.data[i] = i + 3;
	}
	L.length = MaxSize -5;
	result = SubtractList(&L, 3, &e);
	if (result)
	{
		for (i = 0; i < MaxSize; i++)
		{
			printf("data[%d] : %d\n", i, L.data[i]);
		}
		printf("e is %d\n", e);
	}
	else
	{
		printf("subtracted failed!\n");
	}
}
