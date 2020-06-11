#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct Teacher
{
	char name[64];
	char *pname;
	int age;
	int id;
};

int main()
{
	struct Teacher p1;
	struct Teacher *p2;

	p2 = &p1;
	int offsize = (int)&(p2 -> age) - (int)p2;
	printf("%d\n", offsize);
	
	p2 = NULL;
	offsize = (int)&(p2 -> age);
	printf("%d\n", offsize);
}
