#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

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

bool BinarySearch(SqList *L, int n, int *e)
{
	// int first = 0, end = L -> length - 1, mid = (first + end) / 2;
	// while (L -> data[mid] != n)
	// {
	// 	if (L -> data[mid] > n && mid >= first)
	// 	{
	// 		mid--;
	// 	}
	// 	else if (L -> data[mid] < n && mid <= end)
	// 	{
	// 		mid++;
	// 	}
	// 	else
	// 		break;
	// }
	int low = 0, high = L -> length - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (L -> data[mid] == n)
		{
			*e = mid;
			return true;
		}
		else if (L -> data[mid] < n)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return false;
}

bool InsertEle(SqList *L, int n)
{
	if (L -> length < L -> MaxSize)
	{
		if (n < L -> data[0])
		{
			int i;
			for (i = L -> length - 1; i >= 0; i--)
			{
				L -> data[i + 1] = L -> data[i];
			}
			L -> data[0] = n;
		}
		else if (n > L -> data[L -> length - 1])
		{
			L -> data[L -> length] = n;
		}
		L -> length++;
		return true;
	}
	else
	{
		IncreaseList(L, 3);
		if (n < L -> data[0])
		{
			int i;
			for (i = L -> length - 1; i >= 0; i--)
			{
				L -> data[i + 1] = L -> data[i];
			}
			L -> data[0] = n;
		}
		else if (n > L -> data[L -> length - 1])
		{
			L -> data[L -> length] = n;
		}
		L -> length++;
		return true;
	}
	return false;
}

bool ExchangeAddr(SqList *L, int n)
{
	int temp;
	temp = L -> data[n];
	L -> data[n] = L -> data[n + 1];
	L -> data[n + 1] = temp;
	return true;
}

int main()
{
	SqList L;
	int i, index = 0, e;
	bool result;
	InitList(&L);
	for (i = 0; i < L.MaxSize - 3; i++)
	{
		L.data[i] = i + 3;
	}
	L.length = L.MaxSize - 3;
	IncreaseList(&L, 3);
	result = BinarySearch(&L, 0, &e);
	printf("e is %d\n", e);
	if (result)
	{
		printf("true\n");
		ExchangeAddr(&L, e);
	}
	else
	{
		printf("false\n");
		InsertEle(&L, 12);
	}
	// if (index < 0 || index > L.length - 1)
	// {
	// 	result = InsertEle(&L, 12);
	// }
	// else
	// {
	// 	result = ExchangeAddr(&L, index);
	// }
	// printf("the index is %d\n", index);
	for (i = 0; i < L.length; i++)
	{
		printf("data[%d] : %d\n", i, L.data[i]);
	}
	printf("MaxSize is %d\n", L.MaxSize);
}
