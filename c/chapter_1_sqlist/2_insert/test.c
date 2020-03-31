#include<stdio.h>

void fun(int **A)
{
	printf("the A is %p, the A address is %p\n", A, *A);
	**A = 10;
}

int main()
{
	int i = 2;
	int *address;

	address = &i;
	printf("the address is %p, &address is %p\n", address, &address);
	fun(&address);
	printf("i = %d\n", i);
}
