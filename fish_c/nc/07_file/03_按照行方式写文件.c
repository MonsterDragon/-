#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp = NULL;
	char a[64] = "shuzhan";
	char *filename = "./test.txt";

	fp = fopen(filename, "w+");
	if (fp == NULL)
	{
		printf("exec error: %d\n", -1);
	}

	fputs(a, fp);
	fclose(fp);
}
