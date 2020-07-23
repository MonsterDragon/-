#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

void printArray(int *t, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("i: %d value: %d\n", i, *(t + i));
	}
}

void Sort(int *array, int len)
{
	int tmp, i = 0, j = 0;
        
        for (i = 0; i < len - 1; i++)
        {       
                for (j = i + 1; j < len; j++)
                {       
                        if (array[i] > array[j])
                        {       
                                tmp = array[i];
                                array[i] = array[j];
                                array[j] = tmp;
                        }
                }
        }

}

int main()
{
        int array[] = {12, 11, 422, 98, 10, 7};
        int len = sizeof(array) / sizeof(*array);

        printArray(array, len);
        Sort(array, len);
        printArray(array, len);
}
