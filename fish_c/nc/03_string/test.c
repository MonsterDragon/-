#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int a[2] = {1, 2};
	a[0] = a[1];
	char tt[3] = "aab";
	tt[0] = tt[2];
	printf("%s\n", tt);
}
