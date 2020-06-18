#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"seqstack.c"


int main()
{
	int i = 0, capacity = 10;
	int a[10] = {0};
	SeqStack* stack= NULL;

	stack = (SeqStack*)SeqStack_Create(capacity);
	if (stack == NULL)
	{
		printf("SeqStack_Create failed!\n");
	}
	
	// 压栈
	for (i = 0; i < 5; i++)
	{
		a[i] = i + 2;
		SeqStack_Push(stack, &a[i]);
	}

	// 栈的容量
	printf("the capacity: %d\n", SeqStack_Capacity(stack));
	// 栈的长度
	printf("length: %d\n", SeqStack_Size(stack));
	// 栈顶元素
	printf("top: %d\n", *(int *)SeqStack_Top(stack));

	while (SeqStack_Size(stack) > 0)
	{
		printf("pop: %d\n", *(int *)SeqStack_Pop(stack));
	}

	printf("\n");
}
