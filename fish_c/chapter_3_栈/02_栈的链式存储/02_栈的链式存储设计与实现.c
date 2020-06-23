#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"linkstack.c"

int main()
{
	int i = 0;
	int a[10];

	LinkStack* stack = NULL;
	stack = LinkStack_Create(); 

	if (stack == NULL)
	{
		return ;
	}
 
	// 添加元素
	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		LinkStack_Push(stack, &a[i]); // void* 任意类型指针，没有类型的限制
	}

	// 获取基本属性
	printf("len: %d\n", LinkStack_Size(stack));

	printf("top: %d\n", *((int*)LinkStack_Top(stack)));

	while (LinkStack_Size(stack) > 0)
	{
		printf("pop: %d\n", *((int*)LinkStack_Pop(stack)));
	}
	
	LinkStack_Destroy(stack);
}
