#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"cfg_op.h"
#define Maxlen 2048

// 写修改配置文件
int write(const char *pfile, const char *key, const char *vlaue, int len)
{
	return 0;
}

// 读配置文件
int read(const char *filename, const char *key, char *value)
{
	FILE *fp = NULL;
	// char *filename = pfile;
	char line[Maxlen] = {0};
	char list[Maxlen] = {0};
	int i = 0;

	if (filename == NULL)
	{
		printf("file name is empty: %d\n", -1);
		return -1;
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("file is not exist: %d\n", -1);
		return -1;
	}
	while (!feof(fp))
	{
		fgets(line, Maxlen, fp);
		printf("line is: %s\n", line);

		char *tmp = strchr(line, '=');
		if (tmp == NULL)
		{
			continue;
		}

		char *add = strstr(line, key);
		if (add != NULL)
		{
			int count = 0;
			char *tmp = strchr(line, '=');
			tmp += 1;
			int start = 0, end = strlen(tmp) - 1;
			while (isspace(tmp[start]) && tmp[start] != 0)
				start++;
			while (isspace(tmp[end]) && tmp[end] != 0)
				end--;
			count = end -start + 1;
			strncpy(value, tmp+start, count);
			goto END;
		}
	}
	if (i == 0)
	{
		printf("The key has not be found!\n");
		return -1;
	}
END:
	return 0;
}
