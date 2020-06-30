#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"queue.c"

int main()
{
	int i = 0;
	int a[5] = {0};
	
	Queue* queue = NULL;
	queue = Queue_Create(10);
	if (queue == NULL)
		return;

	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		Queue_Append(queue, &a[i]);
	}

	// 打印队列的属性
	printf("len:%d\n", Queue_Length(queue));
	printf("header:%d\n", *((int*)Queue_Header(queue)));
	printf("capacity:%d\n", Queue_Capacity(queue));

	while(Queue_Length(queue) > 0)
	{
		int tmp = *((int*)Queue_Retrieve(queue));
		printf("tmp:%d\n", tmp);
	}

	Queue_Destroy(queue);
}
