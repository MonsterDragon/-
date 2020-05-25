#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher1; // Teacher1表示变量，Teacher-tag

void output(struct Teacher *p)
{
	int i;
	for (i=0; i<3; i++)
	printf("%d\n", p[i].age);
}

void sort(struct Teacher (*p)[3]) // 数组指针
{
	int i, j;
	struct Teacher tmp;
	for (i=0; i<3; i++)
	{
		for (j=i+1; j<3; j++)
		{
			if ((*p)[i].age > (*p)[j].age)
			{
				tmp = (*p)[i];
				(*p)[i] = (*p)[j];
				(*p)[j] = tmp;
			}
		}
	}
}

int main()
{
	int i;
	struct Teacher array[3];

	for (i=0; i<3; i++)
	{
		printf("\nPlease enter teacher's age: ");
		scanf("%d", &(array[i].age));
	}
	
	output(array);
	sort(&array);
	output(array);
}
