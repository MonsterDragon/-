#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct Teacher
{
	char name[64];
	int age;
};

int main()
{
	FILE *fp = NULL;
	char *filename = "test_02.txt";
	struct Teacher list[3];

	int i;
	for (i=0; i<3; i++)
	{
		sprintf(list[i].name, "%d%d%d", i+1, i+1, i+1); // int sprintf( char *buffer, const char *format, ... );
		list[i].age = i + 5;
	}
	
	fp = fopen(filename, "ab");
	if (fp == NULL)
	{
		printf("open file err: %d\n", -1);
	}
	int count;
	for (i=0; i<3; i++)
	{
		count = fwrite(&list[i], sizeof(struct Teacher), 2, fp); // int fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
		// 返回值是执行成功的次数
		printf("%d\n", count);
	}

	fclose(fp);
}
