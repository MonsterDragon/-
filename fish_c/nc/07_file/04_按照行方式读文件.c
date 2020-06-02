#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp = NULL;
	char a[1024];
	char *filename = "./test.txt";

	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("open file err:%d\n", fp);
	}
	int i = 0;
	while (!feof(fp))
	{
		// 会一行一行的copy数据到buf指针所指的内存空间中并且变成c风格的字符串
		// 把\n叶copy到字符数组的指针中
		// 内存打包（内存的首地址加内存的长度）
		char *p = fgets(a, 1024, fp); // char *fgets( char *str, int num, FILE *stream );
		printf("p is %s, i : %d\n", p, ++i);
		// printf("a is %s\n", a);
		if (p == NULL)
		{
			goto END;
		}
	}
END:
	if (fp != NULL)
	{
		fclose(fp);
	}
}
