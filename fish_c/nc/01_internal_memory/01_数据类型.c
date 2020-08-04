#include<stdio.h>
#include<stdlib.h>
#include"string.h"

struct Teacher
{
	char name[64];
	int age;
};

// 数据类型的别名
typedef struct teacher2
{
	char name[64];
	int age;
}Teacher2;

// 数据类型的本质：固定大小内存块的别名
// 定义一个数组数据类型，数组指针，数组类型和数组指针类型的关系
int main()
{
	int a;
	int b[10];
	printf("b:%d, b+1: %d, &b: %d, &b+1: %d\n", b, b+1, &b, &b+1);
	printf("sizeof(b): %d\n", sizeof(b)); // 40
	printf("sizeof(a): %d\n", sizeof(a)); // 4
	// b和&b的数据类型不相同
	// b代表的是数组首元素的地址
	// &b代表的是整个数组的地址
	
	void *p2 = NULL;
	p2 = malloc(100); // malloc函数返回的是void指针，void指针原则上可以存储所有数据类型的指针，作为右值赋值给其他变量时要强制类型转换
	
}
