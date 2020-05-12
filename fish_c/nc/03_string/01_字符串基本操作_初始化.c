#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// 一级指针的典型用法
// 数组 int a[10]
// 字符串
// 1、C语言的字符串，以零结尾的字符串
// 2、在C语言中没有字符串类型，通过字符数组来模拟字符串
// 3、字符串的内存分配，栈上、堆上、全局区

// 字符数组 初始化
int main()
{
	// 指定长度
	char buf2[100] = {'a', 'b', 'c', 'd'};
	// 1-1 char buf3[2] = {'a', 'b', 'c', 'd'}; // 如果初始化的个数大于内存的个数 编译错误
	// 1-2 // 后面的buf2[4] - buf2[99] 全部为0
	printf("buf2: %s\n", buf2);
	printf("buf2[90]: %d\n", buf2[90]);
	
	// 不指定长度
	char buf1[] = {'a', 'b', 'c', 'd'};
	// buf1是一个数组，不是以0结尾的字符串
}
