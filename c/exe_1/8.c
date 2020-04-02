#include<stdio.h>
#include<stdbool.h>
#define ArraySize 9

typedef int DataType;

bool Reverse(DataType *L, int start, int end, int arraysize)
{
	DataType temp;
	if(start >= end || end >= arraysize)
		return false;
	int mid = (start + end) / 2;
	int i;
	for (i = 0; i <= mid - start; i++)
	{
		temp = L[start + i];
		L[start + i] = L[end - i];
		L[end - i] = temp;
	}
	return true;
}

int main()
{
	DataType L[] = {1, 2, 3, 4, 100, 102, 104, 106, 108};
	int m = 4, n = 5;
	Reverse(L, 0, m+n-1, ArraySize);
	int i;
	Reverse(L, 0, n-1, ArraySize);
	Reverse(L, n, m+n-1, ArraySize);
	for (i = 0; i < ArraySize; i++)
	{
		printf("L[%d] = %d\n", i, L[i]);
	}
}
