#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"function.h"

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
	L -> MaxSize = InitSize;
	L -> length = 0;
}

void IncreaseList(SqList *L, int num)
{
	int *q = L -> data;
	L -> data = (int *)malloc((L -> MaxSize + num) * sizeof(int));
	int i;
	for (i = 0; i < L -> length; i++)
	{
		L -> data[i] = q[i];
	}
	L -> MaxSize += num;
	free(q);
}

// bool Deduplication(SqList *L, SqList *M, SqList *N)
// {
// 	int i, j, m, Len = max(L -> length, M -> length);
// 	printf("Len is %d\n", Len);
// 	for (i = 0, j = 0, m = 1; m < Len; m++)
// 	{
// 		if (L -> length >= m + 1 && L -> data[i] != L -> data[m])
// 			L -> data[++i] = L -> data[m];
// 		if (M -> length >= m + 1 && M -> data[j] != M -> data[m])
// 			M -> data[++j] = M -> data[m];
// 	}
// 	L -> length = i + 1;
// 	M -> length = i + 1;
// 	int minNum, maxNum;
// 	minNum = min(L -> data[0], M -> data[0]); // 只考虑有序表是递增的情况
// 	maxNum = max(M -> data[M -> length - 1], L -> data[L -> length - 1]);
// 	for (i = 0, j = minNum; j <= maxNum; i++, j++)
// 	{
// 		N -> data[i] = j;
// 	}
// 	N -> length = maxNum - minNum + 1;
// 	return true;
// }

bool DeleteSame(SqList *L)
{
	int i, j;
	for (i = 0, j = 1; j < L -> length; j++)
		if (L -> data[i] != L -> data[j])
			L -> data[++i] = L -> data[j];
	L -> length = ++i;
}

bool Merge(SqList *L, SqList *M, SqList *N)
{
	printf("N MaxSize is %d\n", N -> MaxSize);
	printf("sum num is %d\n", L -> length + M -> length);
	if (L -> length + M -> length >  N -> MaxSize)
		return false;
	int i = 0, j = 0, k = 0;
	while (i < L -> length && j < M -> length)
	{
		if (L -> data[i] < M -> data[j])
		{
			N -> data[k++] = L -> data[i++];
		}
		else
		{
			N -> data[k++] = M -> data[j++];
		}
	}
	while (i < L -> length)
	{
		N -> data[k++] = L -> data[i++];
	}
	while (j < M -> length)
	{
		N -> data[k++] = M -> data[j++];
	}
	N -> length = k;
	printf("N length is %d\n", k);
	return true;
}

int main()
{
	SqList L, M, N;
	int i;
	bool result;
	InitList(&L);
	for (i = 0; i < L.MaxSize - 2; i += 2)
	{
		L.data[i] = i + 3;
		L.data[i + 1] = i + 3;
	}
	L.length = L.MaxSize - 3;
	IncreaseList(&L, 3);
	InitList(&M);
	for (i = 0; i < M.MaxSize; i += 3) 
	{
		M.data[i] = i + 2;
		M.data[i + 1] = i + 2;
		M.data[i + 2] = i + 2;
	}
	M.length = M.MaxSize;
	for (i = 0; i < L.length; i++)
	{
		printf("data[%d] : %d\n", i, L.data[i]);
	}
	for (i = 0; i < M.length; i++)
	{
		printf("data[%d] : %d\n", i, M.data[i]);
	}
	printf("MaxSize is %d\n", M.MaxSize);
	InitList(&N);
	DeleteSame(&L);
	DeleteSame(&M);
	for (i = 0; i < L.length; i++)
	{
		printf("data[%d] : %d\n", i, L.data[i]);
	}
	for (i = 0; i < M.length; i++)
	{
		printf("data[%d] : %d\n", i, M.data[i]);
	}
	IncreaseList(&N, 20);
	result = Merge(&L, &M, &N);
	if (result)
	{
		printf("\n\n");
		for (i = 0; i < N.length; i++)
		{
			printf("data[%d] : %d\n", i, N.data[i]);
		}
	}
}
