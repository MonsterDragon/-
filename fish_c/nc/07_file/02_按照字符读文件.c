#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp = NULL;
	char a[64] = {};
	char *filename = "/data/spider/envicool.py";
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("func fopen() err:%d\n", -1);
	}

	int i = 0;
	for (i=0; i<64; i++)
	{
		a[i] = fgetc(fp);// char *fgets( char *str, int num, FILE *stream );
		printf("%c\n", fgetc(fp));
	}
	// while(!feof(fp))
	// {
	// 	char tmc = fgetc(fp);
	// 	printf("%c\n", tmc);
	// 	a[i++] = tmc;
	// 	if (i == 64)
	// 	{
	// 		break;
	// 	}
	// }
	fclose(fp);
	printf("%s\n", a);
}
