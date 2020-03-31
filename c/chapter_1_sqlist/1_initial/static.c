#include <stdio.h>
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
		L->data[i] = 0;
	}
	L->length = 0;
	printf("initlist location is %p\n", L);
}

int main()
{
	int i;
	SqList L;
	InitList(&L);
	for (i = 0; i < MaxSize; i++)
	{
		printf("data[%d] = %d\n", i + 1, L.data[i]);
	}
	printf("The length is %d\n", L.length);
	printf("main location is %p\n", &L);
}
