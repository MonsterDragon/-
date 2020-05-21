#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

void printarray(int *p, int num)
{
	int i;
	for (i=0; i<num; i++)
	{
		printf("%d\n", p[i]);
	}
}

int main()
{
	int array[3][5];
	int i, j, tmp = 1;

	for (i=0; i<3; i++)
	{
		for (j=0; j<5; j++)
		{
			array[i][j] = tmp++;
		}
	}
	printarray((int *)array, 15); // 指针的强制转换，将一位数组转化为二维数组
	// 数组指针的等价关系
	//       数组参数	    ===>        等效指针形参
	// 一维数组 char a[30] 			指针 char *a
	// 指针数组 char (*a)[30]    		二级指针 char **a
	// 二维数组 char a[3][5]		指针数组 char (*a)[5]; char a[][5]
}
