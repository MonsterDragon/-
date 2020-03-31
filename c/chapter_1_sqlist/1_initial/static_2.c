#include<stdio.h>
#define MaxSize 12

typedef struct 
{
	int data[MaxSize];
	int length;
}SqList;

void InitList(SqList *L)
{
	int i;
	printf("the location in initlist %p\n", L);
	L->length = 0;
	//for (i = 0; i < MaxSize; i++)
	//{
	//	L.data[i] = 0;
	//}
}

int main()
{
	int i;
	SqList *L;
	InitList(L);
	for (i = 0; i < MaxSize; i++)
	{
		printf("data[%d] = %d\n", i, L->data[i]);
	}
}
