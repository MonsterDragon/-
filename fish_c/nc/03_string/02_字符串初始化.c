#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// 用字符串初始化字符数组
// strlen() sizeof()
int main()
{
	char *buf = "abababab";
	char buf1[] = "cdcdcdcd"; // buf1作为字符数组，应该是5个字节 // 作为字符串， 应该是四个字节

	int len = strlen(buf);
	printf("len : %d\n", len);

	printf("sizeof: %d\n", sizeof(buf));
	printf("sizoef buf1: %d\n", sizeof(buf1));
	printf("len buf1: %d\n", strlen(buf1));
}
