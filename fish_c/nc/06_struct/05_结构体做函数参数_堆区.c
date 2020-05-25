#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct Teacher
{
	char name[64];
	int age;
	int id;
};

struct Teacher * create(int num)
{
	struct Teacher *p = (struct Teacher *)malloc(sizeof(struct Teacher) * num);
	return p;
}

void output(struct Teacher *p)
{
	int i;
	for (i=0; i<3; i++)
	{
		printf("%d\n", p[i].age);
	}
}

void free_array(struct Teacher **p)
{
	if (p == NULL)
	{
		return;
	}
	free(*p);
	*p = NULL;
}

int main()
{
	struct Teacher *array;
	array = create(3);
	int i;
	for (i=0; i<3; i++)
	{
		printf("\nPlease enter age: ");
		scanf("%d", &(array[i].age));
	}
	output(array);
	free_array(&array);
}
