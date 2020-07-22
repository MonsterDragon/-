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

void InsertionSort(int *t, int len)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;

	for (i = 1; i < len; i++)
	{
		k = i;
		temp = t[k];
		for (j = i - 1; (j >= 0) && (t[j] > temp); j--)
		{
			t[j+1] = t[j];
			k = j;
		}
		t[k] = temp;
	}
}

int main()
{
	int array[] = {12, 11, 422, 98, 10, 7};
	int len = sizeof(array) / sizeof(*array);

	printArray(array, len);
	InsertionSort(array, len);
	printArray(array, len);
}
