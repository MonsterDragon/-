#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// 1级指针

void modify(int *d)
{
	*d = 100;
}

void main1()
{
	 int a = 10;
	a = 20; 
	int *p = NULL;
	p = &a;
	*p = 30;
	printf("a: %d\n", a);
	*p = 40;
	printf("a: %d\n", a);

	modify(p);
	printf("a: %d\n", a);
}

// 二级指针间接修改一级指针

void getmem(char **p2)
{
	*p2 = 400;
}

void main2()
{
	char *p = NULL;
	char **p1 = NULL;

	p = 0x334;
	p1 = 0x66009;

	p1 = &p;
	*p1 = 2222;
	printf("p: %d\n", p);
	getmem(p1);
	printf("p: %d\n", p);
}

void getnum(char **my1, int *len1, char **my2, int *len2)
{
	*my1 = (char *)malloc(100);
	strcpy(*my1, "asasaasasas");
	*len1 = strlen(*my1);

	*my2 = (char *)malloc(100);
	strcpy(*my2, "asgajgasdj");
	*len2 = strlen(*my2);
}

void main()
{
	char *p1 = NULL, *p2 = NULL;
	char *p3 = NULL;
	int len1, len2;
	getnum(&p1, &len1, &p2, &len2);
	printf("p1:%s, p2:%s, len1:%d, len2:%d\n", p1, p2, len1, len2);
	p3 = "asasasasancksndc";
	printf("p3:%s\n", p3);
	free(p1);
	p1 = NULL;
	free(p2);
	p2 = NULL;

	// 数组的复制，通过指针的赋值
	char *from = "aaaaabbbbb";
	char *to = NULL;
	char *end = NULL;
	to = (char *)malloc(100);
	end = to;
	while (*from != '\0')
	{
		*to = *from;
		printf("to: %c\n", *to);
		from++;
		to++;
	}
	printf("end: %s\n", end);
}
