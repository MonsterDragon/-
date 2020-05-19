#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

void printarray(char **p, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("p[%d]: %s\n", i, p[i]);
	}
}

void sortarray(char **p, int n)
{
	int i, j;
	char *tmp;
	
	for (i=0; i<n; i++)
	{
		for (j=i+1; j<n; j++)
		{
			if (strcmp(p[i], p[j]) < 0)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}

void freemem(char **p, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;
}

int main()
{
	char **array = (char **)malloc(sizeof(char *) * 9);
	int i, num = 9;

	for (i=0; i<num; i++)
	{
		array[i] = (char *)malloc(sizeof(char) * 100);
		sprintf(array[i], "%d%d%d", i+1, i+1, i+1);
	}

	printarray(array, num);
	sortarray(array, num);
	printarray(array, num);
	freemem(array, num);
}
