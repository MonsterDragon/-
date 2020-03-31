#include<stdio.h>
#include<stdbool.h>
#define MaxSize 10

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

bool InsertList(SqList *L, int i, int e)
{
	int num;
	if (MaxSize <= L -> length)
		return false;
	if (i > L -> length + 1 || i < 1)
		return false;
	else
	{
                for (num = L -> length; num >= i; num--)
		{   
			L -> data[num] = L -> data[num - 1]; 
		}   
		L -> data[i - 1] = e;
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
		L.data[i] = i;
	}
	L.length = MaxSize - 5;
	result = InsertList(&L, 3, 88);
	if (result)
	{
		printf("Execute successful!\n");
	}
	else
	{
		printf("Execute failed!\n");
	}
	for (i = 0; i < MaxSize; i++)
	{
		printf("data[%d] : %d\n", i, L.data[i]);
	}
}
