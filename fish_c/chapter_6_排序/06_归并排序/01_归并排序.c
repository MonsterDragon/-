#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

printArray(int *array, int len)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		printf("seq: %d, value: %d\n", i, array[i]);
	}
}

void Merge(int *src, int *des, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while ((i <= mid) && (j <= high))
	{
		if (src[i] < src[j])
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while (i <= mid)
	{
		des[k++] = src[i++];
	}

	while (j <= high)
	{
		des[k++] = src[j++];
	}
}

void MSort(int *src, int *des, int low, int high, int len)
{
	if (low == high)
	{
		des[low] = src[low];
	}
	else // 多个元素进行两路归并
	{
		int mid = (low + high) / 2;
		int *space = (int*)malloc(sizeof(int) * len);
		if (space != NULL)
		{
			MSort(src, space, low, mid, mid + 1);
			MSort(src, space, mid + 1, high, high-mid);
			Merge(space, des, low, mid, high); // 调用归并函数进行归并
		}

		free(space);
	}
}

int* MergeSort(int *array, int len)
{
	int *des = (int *)malloc(sizeof(int) * len);
	MSort(array, des, 0, len - 1, len);
	return des;
}

int main()
{
	int array[] = {12, 11, 422, 98, 10, 7};
        int len = sizeof(array) / sizeof(*array);

        printArray(array, len);
        int *des = MergeSort(array, len);
        printArray(des, len);
}
