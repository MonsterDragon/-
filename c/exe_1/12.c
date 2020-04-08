#include<stdio.h>
#include<stdlib.h>

// 时间复杂度是冒泡排序的O(n^2)，空间复杂度是O(1)。算法原地工作是指算法所需的辅助空间为常量
int ResearchMain(int *data, int n)
{
	int *L = (int *)malloc((n - 1) * sizeof(int));
	int i, j, tmp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (data[j] > data[j + 1])
			{
				tmp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = tmp;
			}
		}
	}
	int m;
	printf("n / 2 is %d\n", n / 2);
	for (i = 1, m = 1; i < n && m < n / 2; i++, m++)
	{
		if (data[i] != data[i - 1])
		{
			m = 1;			
		}
		printf("m is %d\n", m);
	}
	printf("the main num is %d\n", data[i - 1]);
}

// 时间复杂度是O(n)，空间复杂度是O(n)
int SpacetoTime(int *L, int n)
{
	int *statics = (int *)malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++)
	{
		statics[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		statics[L[i]]++;
	}
	for (i = 0; i < n; i++)
	{
		printf("statics[%d] : %d\n", i, statics[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (statics[i] >= n / 2)
		{
			return i;
		}
	}
}

int main()
{
	int result, length;
	int data1[] = {1, 3, 3, 3, 2, 6, 8, 10, 3, 6, 3, 3};
	length = sizeof(data1)/sizeof(int);
	// result = ResearchMain(data1, length);
	result = SpacetoTime(data1, length);
	printf("result is %d\n", result);
	int i;
	for (i = 0; i < length; i++)
	{
		printf("data1[%d] : %d\n", i, data1[i]);
	}
}
