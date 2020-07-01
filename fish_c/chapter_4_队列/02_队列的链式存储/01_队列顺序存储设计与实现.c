#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"linkqueue.c"

int main()
{
	int i = 0;
	int a[5] = {0};
	
	LinkQueue* queue = NULL;
	queue = LinkQueue_Create(10);
	if (queue == NULL)
		return;

	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		LinkQueue_Append(queue, &a[i]);
	}

	// 打印队列的属性
	printf("len:%d\n", LinkQueue_Length(queue));
	printf("header:%d\n", *((int*)LinkQueue_Header(queue)));

	while(LinkQueue_Length(queue) > 0)
	{
		int tmp = *((int*)LinkQueue_Retrieve(queue));
		printf("tmp:%d\n", tmp);
	}

	LinkQueue_Destroy(queue);
}
