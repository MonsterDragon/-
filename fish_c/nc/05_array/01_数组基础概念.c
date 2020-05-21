#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a[] = {1, 2};
	int b[100] = {1, 3};
	
	int c[200] = {0}; // 编译时就已经确定所有的值为零

	memset(c, 0, sizeof(c)); // 重置内存块
	// c是数组首元素的地址 c+1步长4个字节
	// &c是整个数组的地址 // &c + 1的步长是200*4
	
	// 怎样表达int a[10]这种数据类型？int []
	// 类型的本质：固定大小内存块的别名
	// 定义数组类型
	typedef int (MyArray)[6]; // 定义了一个数组数据类型
	MyArray array;
	int i;

	for (i=0; i<6; i++)
	{
		array[i] = i+1;
	}

	for (i=0; i<6; i++)
	{
		printf("%d\n", array[i]);
	}
	printf("%p代表数组收元素的地址, %p + 1表示指针移动一个元素的单元长度\n", array, array+1);
	printf("%p, %p\n", &array, &array+1);
}
