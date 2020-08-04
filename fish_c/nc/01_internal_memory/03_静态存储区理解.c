#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int b = 20;
int c = 30;

char * getstr1()
{
	static int a = 10;
	char *p1 = "asbkv";
	a++;
	printf("%d\n", a);
	b++;
	c++;
	return p1;
}

char * getstr2()
{
	char *p2 = "asbkv";
	b++;
	c++;
	return p2;
}

void main()
{
	char *p1;
	char *p2;
	p1 = getstr1();
	p2 = getstr2();
	printf("p1:%p\n", p1);
	printf("p2:%p\n", p2);
	printf("p1:%s; p2:%s\n", p1, p2);
	getstr1();
	getstr1();
	getstr1();
	getstr1();
	getstr1();
	printf("%d\n", b);
	printf("%d\n", c);
}

// 11
// p1:0x4006b0
// p2:0x4006b0
// p1:asbkv; p2:asbkv
// 12
// 13
// 14
// 15
// 16
// 27
// 总结：
// 	c语言：静态变量在函数返回后不会被回收，可以进行多次的运算。静态全部变量作用于源文件，静态局部变量作用于函数，全局变量作用于整个源程序
// 	python：全局变量同c语言，但是没有静态变量的概念
