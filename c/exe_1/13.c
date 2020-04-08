#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int LeastInt(int *L, int n)
{
	int *data = (int *)malloc(n * sizeof(int));
	memset(data, 0, sizeof(int) * n); // 赋初值为0
	int i;
	for (i = 0; i < n; i++)
	{
		if (L[i] > 0 && L[i] <= n)
		{
			data[L[i] - 1]++;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (data[i] == 0)
		{
			return i+1;
		}
	}
}

int main()
{
	int data[] = {2, 4, 1, 6, 8, -2};
	int length = sizeof(data) / sizeof(int);
	int result;
	result = LeastInt(data, length);
	printf("num is %d\n", result);
}
