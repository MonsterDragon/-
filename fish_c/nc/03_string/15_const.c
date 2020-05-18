#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

void getmem_01(const char *p)
{
	// p指针所指向的内存空间的值是不能更改的	
}

void getmem_02(char const *p)
{
	// 不能更改p的指针变量
}

void getmem_03(const char const *p)
{
	// 既不能修改p的指针变量也不修改指针所指向的内存空间
	// 结论C语言中的const修饰的变量是假的，可以通过指针来绕过
}

int main()
{
	char *p = "aaaa";
	getmem_01(p);
}
