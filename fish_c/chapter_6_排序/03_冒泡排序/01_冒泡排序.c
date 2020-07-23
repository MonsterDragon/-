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

void BubbleSort(int array[], int len) // 向右冒泡
{
	int i = 0, j = 0, temp = 0;
	printf("%d\n", len);
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void BubbleSort_2(int *array, int len) // 向左冒泡
{
	int i = 0, j = 0, temp = 0;
	for (i = 0; i < len -1; i++)
	{
		for (j = len - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
	}
}

void Update_BubbleSort_2(int *array, int len)
{
	int i = 0, j = 0, temp = 0, exchange = 1; // 0表示数组已经排好序，1表示数组没有排好序
	
	for (i = 0; (i < len - 1) && exchange; i++) // 外循环表明一共要循环几次
	{
		exchange = 0;
		for (j = len - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
                        {
                                temp = array[j - 1];
                                array[j - 1] = array[j];
                                array[j] = temp;
				exchange = 1;
                        }
		}
	}
}

int main()
{
	int array[] = {12, 11, 422, 98, 10, 7};
        int len = sizeof(array) / sizeof(*array);

        printArray(array, len);
        Update_BubbleSort_2(array, len);
        printArray(array, len);
}
