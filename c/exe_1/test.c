#include<stdio.h>
#include"function.h"

int main()
{
	int i, aa = 5;
	int data[] = {2, 3, 4, 5, 6, 7};
	for (i = 0; i < 10, i < 8; i++)
	{
		printf("data[%d] = %d", i, data[i]);
	}
	printf("++5 = %d\n", data[++aa]);
	printf("5++ = %d\n", data[aa++]);
	printf("%d\n", aa/2);
}

