#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int array[3][5];
	int i, j, tmp=3;

	for (i=0; i<3; i++)
	{
		for (j=0; j<5; j++)
		{
			array[i][j] = tmp++;
		}
	}
	for (i=0; i<3; i++)
	{
		for (j=0; j<5; j++)
		{
			printf("array[%d][%d]: %d\n", i, j, array[i][j]);
		}
	}

	// a多维数组名代表？
	printf("a: %p, a+1: %p\n", array, array+1); // a+1的步长是20个字节
	printf("&a: %p, &a+1: %p\n", &array, &array+1);
	{
		int (*pArray)[5]; // 定义数组的数组指针变量
		pArray = array;
	
		for (i=0; i<3; i++)
		{
			for (j=0; j<5; j++)
			{
				printf("array[%d][%d]: %d\n", i, j, pArray[i][j]);
			}
		}
	}

	// 多维数组的本质 -- 数组（类型）指针，步长等于一维数组长度
	//
	// (a + i)代表是整个第i行的地址 二级指针
	// *(a + i)代表是第i行首元素的地址 一级指针
	// *(a + i) + j 代表第i行第j列的地址 一级指针 ==》&a[i][j]
	// *(*(a + i) + j) => a[j][j]
}
