#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct Teacher
{
	char name[64];
	char **dis;
	int age;
	int id;
};

int create_array(struct Teacher **p, int n)
{
	if (p == NULL)
		return -1;
	int i;
	*p = (struct Teacher *)malloc(sizeof(struct Teacher) * n);
	return 1;
}

void value(struct Teacher *p, int n)
{
	int i;
	int j;
	for (i=0; i<n; i++)
	{
		printf("\nPlease enter discribe: ");
		p[i].dis = (char **)malloc(sizeof(char *) * 3);
		for (j=0; j<3; j++)
		{
			(p[i].dis)[j] = (char *)malloc(sizeof(char) * 10);
			scanf("%s", (p[i].dis)[j]);
			printf("\n");
		}
		printf("sizoef *(p[%d].dis): %d\n", i, sizeof((p[i].dis)[j]));
	}
}

void printarray(struct Teacher *p)
{
	int i;
	int j;
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			printf("[%d][%d]: %s\n", i, j, (p[i].dis)[j]);
		}
	}
}

void freemem(struct Teacher **p, int n)
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			free(((*p)[i].dis)[j]);
		}
		free((*p)[i].dis);
	}
	free(*p);
	free(p);
}

int main()
{
	struct Teacher *wan;
	int num = 3;
	int result;	

	result = create_array(&wan, num);
	if (result != 1)
	{
		printf("create err %d\n", result);
	}
	value(wan, num);
	printarray(wan);
	freemem(&wan, num);
}
