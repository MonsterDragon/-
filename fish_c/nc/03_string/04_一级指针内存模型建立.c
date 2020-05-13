#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buf[20] = "aaaa";
	char buf1[] = "bbbb";
	char *p1 = "111111";
	char *p2 = malloc(100);
	strcpy(p2, "333");

	printf("sizeof buf: %d, sizeof buf1: %d\n", sizeof(buf), sizeof(buf1));
}
