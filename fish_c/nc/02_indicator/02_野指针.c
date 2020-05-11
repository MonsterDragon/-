#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 指针变量和它所指向的内存空间变量是两个不同的概念
// 释放了指针所指的内存空间， 但是指针变量本身没有重置成NULL
// 释放指针所指的内存空间的变量后，要重置指针变量为NULL
void main()
{
	char *p = NULL;
	p = (char *)malloc(100);
	strcpy(p, "aaannncsddcs");
	printf("p : %p\n", p);
	free(p);
	printf("p: %p\n", p);
}
