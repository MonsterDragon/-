#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int (*parray)[5]; // 直接定义一个指向数组的 数组指针变量
	int * sarray[5]; // 定义一个包含5个指针元素的数组
	typedef int (myArray)[5];
	myArray array;
	int i;
	for (i=0; i<5; i++)
	{
		array[i] = i+1;
	}
	parray = &array;
	for (i=0; i<5; i++)
	{
		printf("%d\n", (*parray)[i]);
	}
}
