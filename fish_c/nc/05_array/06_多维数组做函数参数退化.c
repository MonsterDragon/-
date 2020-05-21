#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

void printarray_1(int p[3][5])
{
	return;
}

void printarray_2(int p[][5])
{
	return;
}

void printarray_3(int (*p)[5]) // 数组指针，指向包含5个元素的一维数组
{
	return;
}

int main()
{
	int array[3][5];
	int i, j, tmp = 1;
	
	for (i=0; i<3; i++)
	{
		for (j=0; j<5; j++)
		{
			array[i][j] = tmp+1;
		}
	}

	printarray_1(array);
	printarray_2(array);
	printarray_3(array);

	int a[5];
	printarray_1(&a);
	
}
