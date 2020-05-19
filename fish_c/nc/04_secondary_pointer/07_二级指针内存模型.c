#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int i;

	// 指针数组
	char *p_1[] = {"aaaa", "fffff", "cccc"};

	// 二维数组
	char p_2[3][10] = {"aaaa", "fffff", "cccc"};

	// 自定义二维数组
	char **p = (char **)malloc(sizeof(char *) * 3);
	for (i=0; i<10; i++)
	{
		p[i] = (char *)malloc(sizeof(char) * 10);
		sprintf(p[i], "%d%d%d", i, i, i);
	}
}
