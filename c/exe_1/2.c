#include <stdio.h>
#define InitSize 10

typedef struct
{
	int data*;
	int length;
	int MaxSize;
}

bool InvertList(SqList *L)
{
	int i;
	int num;
	for (i = 0; i < L -> length / 2; i++)
	{
		num = L -> data[i];
		L -> data[i] = L -> data[L -> length - 1 - i];
		L -> data[L -> length -1 - i] = num;
	}
	return true;
}

