#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct Teacher
{
	char name[64];
	int age;
	int id;
}t2 = {"bbbb", 12, 20}; // 第二种：定义数据类型的同时定义变量并进行初始化
struct Teacher t3 = {"cccc", 22, 10};

struct
{
	char name[32];
	char age;
	char id;
}t4 = {"dddd", 15, 8};

// 初始化变量的三种方法
int main()
{
	struct Teacher t1 = {"aaaa", 26, 01}; // 第一种：定义变量并进行初始化
	printf("%s\n", t1.name); // . 表示寻址操作（name变量相对于t1的偏移量）在cpu中进行计算，没有操作内存
	printf("%d\n", t2.age);
	printf("%s\n", t3.name);
	printf("%s\n", t4.name);
	// 通过指针的方式操作内存空间
	{
		struct Teacher *p = NULL;
		p = &t2;
		printf("p -> age: %d\n", p -> age);
	}
}
