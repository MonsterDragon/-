#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
	L -> data = (int *)malloc(InitSize * sizeof(int));
	for (i = 0; i < InitSize; i++)
	{
		L -> data[i] = 0;
	}
	L -> length = 0;
	L -> MaxSize = InitSize;
}

bool DeleteEles(SqList *L, int s, int t)
{
	if (s >= t)
		return false;
	else
	{
		int i, k=0;
		for (i = 0; i < L -> length; i++)
		{
			if (L -> data[i] > s && L -> data[i] < t)
			{
				k++;
			}
			else
			{
				L -> data[i - k] = L -> data[i];
			}
		}
		L -> length -= k;
	}
	return true;
}

int main()
{
	int i;
	bool result;
	SqList L;
	InitList(&L);
	for (i = 0; i < L.MaxSize - 2; i ++)
	{
		L.data[i] = i + 3;
	}
	L.length = L.MaxSize - 2;
	result = DeleteEles(&L, 4, 6);
	if (result)
	{
		for (i = 0; i < L.length; i++)
		{
			printf("data[%d] : %d\n", i, L.data[i]);
		}
	}
}
