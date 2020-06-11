#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"cfg_op.h"

int menu()
{
	printf("========================\n");
	printf("输入\'1\'测试写配置文件\n");
	printf("输入\'2\'测试读配置文件\n");
	printf("输入\'0\'表示退出程序\n");
	printf("========================\n");
	return 0;
}

int get_file(char **add)
{

	printf("\n输入配置文件绝对路径: ");
	char *file = (char *)malloc(sizeof(char) * 1024);
	if (file == NULL)
	{
		printf("malloc mem err\n");
		return -1;
	}
	scanf("%s", file);
	*add = file;
}

int Twrite(char *filename)
{
	char name[1024] = {0};
	char value[1024] = {0};
	int ret;
	
	printf("\n请输入key: ");
	scanf("%s", name);
	printf("\n请输入value: ");
	scanf("%s", value);

	ret = write(filename, name, value, strlen(value));
	printf("%d\n", ret);
	if (ret != 0)
	{
		printf("exec write err: %d\n", ret);
		return ret;
	}
	return ret;
}

int Tread(char *filename)
{
	char name[1024] = {0};
	char value[1024] = {0};
	int ret;

	printf("\n请输入key: ");
	scanf("%s", name);
	
	ret = read(filename, name, value);
	if (ret != 0)
	{
		printf("exec read err: %d\n", ret);
		return ret;
	}
	printf("%s\n", value);
	return ret;
}

int main()
{
	int choice;
	char *filename;
	get_file(&filename);

	while (true)
	{
		menu();
		scanf("%d", &choice);
		switch (choice)
		{
			case 1: // 写配置项
				Twrite(filename);
				break;
			case 2: // 读配置项
				Tread(filename);
				break;
			case 0: // 退出程序
				exit(0);
			default:
				exit(0);
		}
	}
}
