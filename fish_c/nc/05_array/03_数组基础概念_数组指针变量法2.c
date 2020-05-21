#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	typedef	int (*myParray)[5]; // 声明一个数组指针类型
	typedef int (Parray)[5];
	Parray array;
	myParray parray = &array;
	int i;
	for (i=0; i<5; i++)
	{
		(*parray)[i] = i+1;
	}
	printf("%p, %p\n", parray, parray+1);
	for (i=0; i<5; i++)
	{
		printf("%d\n", (*parray)[i]);
	}
}
