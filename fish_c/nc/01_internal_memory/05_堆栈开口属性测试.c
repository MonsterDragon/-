#include<stdio.h>

// 一般栈的开口向下
// 不管栈开口向上还是向下，buf的内存地址永远都是buf+1，永远向上
void main()
{
	int a, b;
	printf("a: %p, b: %p\n", &a, &b);

	char buf[128];
	printf("buf: %p, buf+1: %p, &buf[1]: %p\n", buf, buf+1, &buf[1]);
	printf("sizeof char: %d\n", sizeof(char));
}
