#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// 定义数组指针变量的方法1
int main()
{
	typedef int (myArray)[5]; // 声明数组类型
	myArray array;
	int i;
	for (i=0; i<5; i++)
	{
		array[i] = i + 1;
	}
	myArray *parray; // 定义数组类型指针parray
	parray = &array;
	printf("%p, %p\n", parray, parray+1);
	for (i=0; i<5; i++)
	{
		printf("array[%d]: %d\n", i, (*parray)[i]);
	}

	int array_2[5];
	for (i=0; i<5; i++)
	{
		array_2[i] = i + 2;
	}
	parray = &array_2;
	printf("%p, %p\n", parray, parray+1);
	for (i=0; i<5; i++)
	{
		printf("array_2[%d]: %d\n", i, (*parray)[i]);
	}
}
