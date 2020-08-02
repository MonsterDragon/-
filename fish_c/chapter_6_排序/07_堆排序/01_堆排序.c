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

void swap(int *arr, int src, int des)
{
	int sum = arr[src] + arr[des];
	arr[src] = sum - arr[src];
	arr[des] = sum - arr[des];
}

void heap_adjust(int *arr, int start, int end)
{
	int parent = start;
	int child = 2 * start + 1;
	// while (child <= end)
	// {
	// 	if (child + 1 <= end && arr[child + 1] > arr[child])
	// 	{
	// 		child++;
	// 	}
	// 	if (arr[parent] > arr[child])
	// 	{
	// 		return;
	// 	}
	// 	else
	// 	{
	// 		swap(arr, parent, child);
	// 		parent = child;
	// 		child = child * 2 + 1;
	// 	}
	// }
	if (child <= end)
	{
		if (child + 1 <= end && arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[parent] > arr[child])
		{
			return;
		}
		else
		{
			swap(arr, parent, child);
			heap_adjust(arr, child, end); // while循环可以通过递归进行替换
		}
	}
	else
	{
		return;
	}
}

void heap_sort(int arr[], int len)
{
	int i;
	printf("length: %d\n", len);
	// i从最后一个父节点开始调整
	for (i = len / 2 - 1; i >= 0; i--)
	{
		heap_adjust(arr, i, len - 1);
	}

	printArray(arr, len);
	for (i = len - 1; i > 0; i--)
	{
		printf("i: %d\n", i);
		swap(arr, 0, i);
		heap_adjust(arr, 0, i - 1);
	}
}

int main(int argc, char const *argv[]) // 指针数组
{
	int arr[] = {1,34,6,21,98,31,7,4,36,47,39,45,5,2};
	int length = sizeof(arr) / sizeof(int);

	heap_sort(arr, length);
	printArray(arr, length);
}
