#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// 一旦结构体定一下来，则结构体中的成员，内存布局就定下来了
// 可以通过age地址去求整体结构体的地址
struct Teacher
{
	char name[64];
	char *pname;
	int age;
	int id;
};

int main()
{
	struct Teacher p1;
	struct Teacher *p2;

	p2 - 1; // 编译通过，运行通过，在cpu中进行计算
	
	int offsize;
	// offsize = (int)&(p2->age);
	offsize = (int)&(((struct Teacher *)0) -> age);
	printf("%d\n", offsize);
}
