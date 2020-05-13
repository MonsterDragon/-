#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// 为什么int buf[]中的buf变量所指向的内存地址不能更改，因为在函数执行完之后要析构这些变量，若buf所指向的指针改变就不能完全析构我们所创建的变量，因此buf是一个常量指针
int main()
{
	char buf[] = {'a', 'b', 'c', '\0'};
	printf("strlen: %d, sizeof: %d\n", strlen(buf), sizeof(buf));
	int i;
	for (i = 0; i<4; i++)
	{
		printf("buf[%d]: %c\n", i, *(buf+i));
	}
	for (i=0; i<4; i++)
	{
		printf("buf[%d]: %c\n", i, buf[i]);
	}
}
