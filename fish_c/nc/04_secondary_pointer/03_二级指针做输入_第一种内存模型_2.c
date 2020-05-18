#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

void sortmyArray(char **array, int lenth)
{
	int i, j;
	char *tmp;
	for (i=0; i<lenth; i++)
	{
		for (j=i+1; j<lenth; j++)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
}

void printmyArray(char **array, int lenth)
{
	int i;
	for (i=0; i<lenth; i++)
	{
		printf("%s\n", array[i]);
	}
}

int main()
{
	char *myArray[] = {"dddd", "cccc", "bbbb", "aaaa"};
	int num = sizeof(myArray) / sizeof(myArray[0]);

	printmyArray(myArray, num);
	sortmyArray(myArray, num);
	printmyArray(myArray, num);
}
