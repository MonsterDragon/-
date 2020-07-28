#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

void printArray(int *t, int len)
{
        int i = 0;
        for (i = 0; i < len; i++)
        {
                printf("seq: %d, num: %d\n", i, t[i]);
        }
}

void exchange(int *array, int low, int high)
{
	int temp = 0;
	temp = array[low];
	array[low] = array[high];
	array[high] = temp;
}

int partition(int *array, int low, int high)
{
	int pv = array[low];

	while (low < high)
	{
		while ((low < high) && (array[high] >= pv))
		{
			high--; // 比基准大，向后移动
		}

		exchange(array, low, high); // 交换两个指针的值

		while ((low < high) && (array[low] <= pv))
		{
			low++; // 比基准小，向前移动
		}

		exchange(array, low, high);
	}

	return low;
}

void QSort(int array[], int low, int high)
{
	if (low < high)
	{
		// 获取pv值，把数据按照大小分别放到pv值的两侧，并获得pv值的序号
		int pivot = partition(array, low, high);
		printf("%d\n", pivot);
	
		// 对子序列1进行排序
		QSort(array, low, pivot - 1);

		// 对子序列2进行排序
		QSort(array, pivot + 1, high);
	}
}

void QuickSort(int array[], int len)
{
	QSort(array, 0, len - 1);
}

int main()
{
        int array[] = {12, 11, 422, 98, 12, 7};
        int len = sizeof(array) / sizeof(*array);

        printArray(array, len);
        QuickSort(array, len);
        printArray(array, len);	
}
