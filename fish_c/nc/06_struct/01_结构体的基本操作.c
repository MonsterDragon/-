#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// 定义一个结构体类型
// 定义一个数据类型。固定大小内存块的别名
// 类型的重命名
typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher


// 用类型定义变量的方法3中
// 第二种
struct _Teacher
{
	char name[64];
	int age;
	int id;
}s1, s2; // 定义类型的同时定义变量

// 第三种
struct
{
	char name[64];
	int age;
	int id;
}s3, s4; // 定义匿名类型定义变量

int main()
{
	// struct Teacher t1; // 分配内存
	Teacher t2; // 重命名后就不需要struct关键字 第一种
}
