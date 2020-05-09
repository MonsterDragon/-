#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * getstr1()
{
	char *p1 = "asbkv";
	return p1;
}

char * getstr2()
{
	char *p2 = "asbkv";
	return p2;
}

void main()
{
	char *p1;
	char *p2;
	p1 = getstr1();
	p2 = getstr2();
	printf("p1:%p\n", p1);
	printf("p2:%p\n", p2);
	printf("p1:%s; p2:%s\n", p1, p2);
}
