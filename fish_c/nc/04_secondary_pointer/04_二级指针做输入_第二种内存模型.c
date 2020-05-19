#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// void printmyArray(char **array, int length)
/*
第二种的myArray+1和第一种的myArray+1的内存模型不一样
指针的步长不一样，指针所指向的内存空间的数据类型不一样
*/
void printmyArray(char array[10][30], int length)
{
	int i;
	for (i=0; i<length; i++)
	{
		printf("%s\n", array[i]);
	}
}

void sort(char array[10][30], int length)
{
	int i, j;
	char tmp[30];

	for (i = 0; i < length; i++)
	{
		for (j = i+1; j < length; j++)
		{
			if (strcmp(array[i], array[j]) > 0)
			{
				strcpy(tmp, array[i]);
				strcpy(array[i], array[j]);
				strcpy(array[j], tmp);
			}
		}
	}
}

int main()
{
	char myArray[10][30] = {"ddddd", "aaaaa", "zzzzzzzzzz", "ppppp"};
	int num = sizeof(myArray) / sizeof(myArray[0]);
	int len1 = sizeof(myArray);
	int len2 = sizeof(myArray[0]);

	// 多维数组本质，数组元素的步长
	printf("len1: %d, len2: %d, num: %d\n", len1, len2, num);
	
	printmyArray(myArray, num);
	sort(myArray, num);
	printmyArray(myArray, num);
}
