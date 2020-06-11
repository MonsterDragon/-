#include<stdio.h>

void change(int *p)
{
	int i;
	for (i=0; i<10; i++)
	{
		p[i] += 2;
	}
}

void play(int (*p)[10])
{
	printf("successful!\n");
}

int main()
{
	int a[10];
	int i;
	for (i=0; i<10; i++)
	{
		a[i] = i+2;
	}
	change(a);
	for (i=0; i<10; i++)
	{
		printf("a[%d]: %d\n", i, a[i]);
	}
	play(&a);
	printf("%d\n", sizeof(&a));
}
