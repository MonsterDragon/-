#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define InitSize 12

typedef struct
{
	int *data;
	int length;
	int MaxSize;
}SqList;

void InitList(SqList *L)
{
	L -> data = (int *)malloc(InitSize * sizeof(int));
	int i;
	for (i = 0; i < InitSize; i++)
	{
		L -> data[i] = 0;
	}		
	L -> length = 0;
	L -> MaxSize = InitSize;
}

void IncreaseList(SqList *L, int l)
{
	int *q = L -> data;
	int i;
	L -> data = (int *)malloc((L -> MaxSize + l) * sizeof(int));
	for (i = 0; i < L -> length; i++)
	{
		L -> data[i] = q[i];
	}
	L -> MaxSize += l;
}

// bool DeleteEle(SqList *L)
// {
// 	int i, m, k;
// 	k = 0;
// 	m = L -> data[0];
// 	for (i = 1; i < L -> length; i++)
// 	{
// 		if (m == L -> data[i])
// 		{
// 			k++;
// 			printf("k is %d", k);
// 		}
// 		else
// 		{
// 			m = L -> data[i];
// 			L -> data[i - k] = L -> data[i];
// 		}
// 	}
// 	L -> length -= k;
// 	return true;
// }

bool DeleteEle(SqList *L)
{
	if (L -> length == 0)
		return false;
	int i, j;
	for (i = 0, j = 1; j < L -> length; j++)
	{
		printf("aa");
		if (L -> data[i] != L -> data[j])
			L -> data[++i] = L -> data[j];
	}
	return true;
}

int main()
{
	int i;
	bool result;
	SqList L;
	InitList(&L);
	IncreaseList(&L, 3);
	for (i = 0; i < L.MaxSize - 3; i += 2)
	{
		L.data[i] = i + 2;
		L.data[i + 1] = i + 2;
	}
	L.length = L.MaxSize - 3;
	result = DeleteEle(&L);
	if (result)
	{
		for (i = 0; i < L.MaxSize; ++i)
		{
			printf("data[%d] : %d\n", i, L.data[i]);
		}
	}
}
