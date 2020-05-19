#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char **myArray = (char**)malloc(sizeof(char *) * 9);

	int i, j, num = 9;
	// char *tmp;
	char tmp[100];
	for (i=0; i<num; i++)
	{
		myArray[i] = (char *)malloc(sizeof(char) * 100);
		sprintf(myArray[i], "%d%d%d", i+1, i+1, i+1); // 将printf("%d%d%d", i+1, i+2, i+3)的输出发送到myArray[i]中
	}
	for (i=0; i<num; i++)
	{
		printf("myArray[%d]: %s\n", i, myArray[i]);
	}

	// 排序 -- 交换指针
	// for (i=0; i<num; i++)
	// {
	// 	for (j=i+1; j<num; j++)
	// 	{
	// 		if (strcmp(myArray[i], myArray[j]) < 0)
	// 		{
	// 			tmp = myArray[i];
	// 			myArray[i] = myArray[j];
	// 			myArray[j] = tmp;
	// 		}
	// 	}
	// }

	// 排序 -- 交换数据
	for (i=0; i<num; i++)
	{
		for (j=i+1; j<num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) < 0)
			{
				strcpy(tmp, myArray[i]);
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], tmp);
			}
		}
	}

	for (i=0; i<num; i++)
	{
		printf("myArray[%d]: %s\n", i, myArray[i]);
	}

	// 释放内存
	for (i=0; i<num; i++)
	{
		free(myArray[i]);
		myArray[i] = NULL;
	}

	if (myArray != NULL)
	{
		free(myArray);
		myArray = NULL;
	}
}
