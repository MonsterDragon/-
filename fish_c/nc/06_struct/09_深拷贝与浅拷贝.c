#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct Teacher
{
	char name[64];
	int age;
	int id;
	char *name2;
};

// 编译器的等号或memcpy，只会把指针变量的值从from copy到通，但是不会把指针变量所指向的内存空间也copy过去。
// 浅copy结构体中套一个一级指针或二级指针就导致两个指针变量指向同一块内存空间
// 当第一个空间的内存free后，又free了一遍相同的内存空间
void copyTeacher(struct Teacher *t1, struct Teacher *t2)
{
	// 浅拷贝
	*t2 = *t1;
	// 深拷贝
	t2 -> name2 = (char *)malloc(sizeof(char) * 100);
	strcpy(t2 -> name2, t1 -> name2);
	// memcpy(t2, t1, sizeof(struct Teacher));
}

int main()
{
	struct Teacher t1;
	struct Teacher t2;

	t1.name2 = (char *)malloc(sizeof(char) * 100);
	strcpy(t1.name, "name1");
	strcpy(t1.name2, "name2");

	// t1 赋值给 t2
	copyTeacher(&t1, &t2);

	if (t1.name2 != NULL)
	{
		free(t1.name2);
		t1.name2 = NULL;
	}
	if (t2.name2 != NULL)
	{
		free(t2.name2);
		t2.name2 = NULL;
	}
}
