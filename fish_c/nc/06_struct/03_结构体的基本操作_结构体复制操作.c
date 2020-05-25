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

void copy(struct Teacher *to, struct Teacher *from)
{
	*to = *from;
	printf("%s\n", (*to).name);
}

int main()
{
	struct Teacher p1 = {"aaaa", 12, 10};
	struct Teacher p2;
	p2 = p1; // 结构体赋值的操作，结构体可以进行相互赋值
	printf("p2.name: %s\n", p2.name);

	struct Teacher p3;
	copy(&p3, &p1);
	printf("%s\n", p3.name);
}
