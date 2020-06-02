#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp= NULL; // 句柄：内存块的首地址
	char *filename = "/data/spider/envicool.py";
	char a[22] = "aaaaaaaaa";
	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("func open() err:%d \n", -1);
	}

	int i;
	for (i=0; i<strlen(a); i++)
	{
		fputc(a[i], fp);
	}
	fclose(fp);
}
