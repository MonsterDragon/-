#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int createarray(char ***p, int n)
{
	char **array;
	if (p == NULL)
	{
		return -1;
	}
	array = (char **)malloc(sizeof(char *) * n);
	int i;
	for (i=0; i<n; i++)
	{
		array[i] = (char *)malloc(sizeof(char) * 8);
		sprintf(array[i], "%d%d%d", i+1, i+1, i+1);
	}
	*p = array;
	printf("%p\n", *p);
}

void printarray(char ***array, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%s\n", (*array)[i]);
	}
}

int main()
{
	char **array = NULL;
	int num = 5;

	createarray(&array, num);
	printf("array:%p\n", array);
	printarray(&array, num);
}
