#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

char * getstr()
{
	char *tmp = NULL;
	tmp = "asdfg";
	return tmp;
}

void main()
{
	int a = 10;
	int *a1 = &a;
	int ****a2 = NULL;
	int *x = NULL;
	x = &a;

	printf("a: %d, a1: %d, a2: %d\n, b: %d\n", sizeof(a), sizeof(a1), sizeof(a2), sizeof(x));

	int *b = &a;
	*b = 20;
	printf("a:%d\n", a);

	int c;
	c = *b;
	printf("c:%d\n", c);

	// 常量区的常量（常量字符串）是无法被修改的
	char *p = getstr() ;
	printf("%s\n", p);
	// p[1] = "c";
	// *(p+2) = "c";
	printf("%s\n", p);

	// 指针做函数参数，形参有多级指针的时候，站在编译器的角度，只需要分配4个字节的内存（32bit）
	// 当我们使用内存的时候，我们才关心指针所指向的内存是一位的还是二维的
	// 指针是一种数据类型，是指它指向的内存空间的数据类型
	// 指针的步长，根据所指内存空间类型来定
}
