#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void printArray(int *array, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("i: %d value: %d\n", i, array[i]);
	}
}

// 希尔算法是不稳定的（由于多次插入排序，我们知道一次插入排序是稳定的，不会改变相同元素的相对顺序，但在不同的插入排序过程中，相同的元素可能在各自的插入排序中移动，最后其稳定性就会被打乱）
// 时间复杂度根据增量数列的选取而不同 -- 见时间复杂度
void HellSort(int *array, int len)
{
	int i = 0, j = 0, k = -1, temp = -1, gap = len;

	do
	{
		gap = gap / 3 + 1;

		for (i = gap; i < len; i++)
		{
			k = i;
			temp = array[k];
			for (j = i - gap; (j >= 0) && (array[j] > temp); j -= gap)
			{
				array[j + gap] = array[j];
				k = j;
			}
			array[k] = temp;
		}
	}while(gap > 1);
}

int main()
{
	clock_t start_t, end_t;
	double total_t;
	int array[] = {12, 11, 422, 98, 10, 7};
        int len = sizeof(array) / sizeof(*array);

        printArray(array, len);
	start_t = clock();
        HellSort(array, len);
	end_t = clock();
	total_t = end_t - start_t;
	printf("running time: %f\n", total_t);
        printArray(array, len);
}
