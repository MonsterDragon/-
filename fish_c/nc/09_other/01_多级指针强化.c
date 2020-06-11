#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char **p = NULL;
	char ***p3 = NULL;
	
	p3 = &p;
	*p3 = 10;
	printf("%p\n", p);
}
