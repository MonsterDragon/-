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

void createTeacher(struct Teacher **array, int num)
{
	*array = (struct Teacher *)malloc(sizeof(struct Teacher) * num);
}

int main()
{
	struct Teacher *array; // 表示一维数组指针
	int num = 3;
	createTeacher(&array, num);
	printf("%d\n", sizeof(*array));
}
