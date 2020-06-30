#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"
// 队列是一种特殊的线性表
typedef struct myqueue
{
	int length;
	int capacity;
	unsigned long int *node;
}Sequeue;

Queue* Queue_Create(int l)
{
	int ret = 0;
	Sequeue* tmp = NULL;

	tmp = (Sequeue*)malloc(sizeof(Sequeue));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func exec Queue_Create err: %d\n", ret);
		return NULL;
	}

	memset(tmp, 0, sizeof(Sequeue));

	tmp -> node = (long int*)malloc(sizeof(long int) * l);
	if (tmp -> node == NULL)
	{
		ret = -2;
		printf("func exec Queue_Create err: %d\n", ret);
                return NULL;
	}

	tmp -> capacity = l;
	tmp -> length = 0;

	return tmp;
}

// 尾插法
int Queue_Append(Queue* queue, void* item)
{
	int ret = 0;
	Sequeue* tmp = (Sequeue*)queue;
	if (tmp == NULL || item == NULL)
	{
		ret = -1;
		printf("func exec Queue_Append err: %d\n", ret);
                return ret;
	}

	if (tmp -> capacity == tmp -> length)
	{
		ret = -2;
		printf("func exec Queue_Append err: %d\n", ret);
                return ret;
	}

	(tmp -> node)[tmp -> length] = (unsigned long int)item;
	tmp -> length++;
	
	return 0;
}

int Queue_Length(Queue* queue)
{
	int ret = 0;
	Sequeue* tmp = (Sequeue*)queue;

	if (tmp == NULL)
	{
		ret = -1;
                printf("func exec Queue_Length err: %d\n", ret);
                return ret;
	}

	return tmp -> length;
}

int Queue_Capacity(Queue* queue)
{
	int ret = 0;
	Sequeue* tmp = (Sequeue*)queue;

	if (tmp == NULL)
        {
                ret = -1;
                printf("func exec Queue_Capacity err: %d\n", ret);
                return ret;
        }

	return tmp -> capacity;
}

void* Queue_Header(Queue* queue)
{
	int ret = 0;
        Sequeue* tmp = (Sequeue*)queue;

        if (tmp == NULL)
        {
                ret = -1;
                printf("func exec Queue_Header err: %d\n", ret);
                return NULL;
        }

	unsigned long int it = *(tmp -> node);
	return (void*)it;
}

void* Queue_Retrieve(Queue* queue)
{
	int ret = 0; 
        Sequeue* tmp = (Sequeue*)queue;
        
        if (tmp == NULL)
        {       
                ret = -1;
                printf("func exec Queue_Retrieve err: %d\n", ret);
                return NULL;
        }

	unsigned long int it = *(tmp -> node);
	int i = 0;
	for (i = 1; i < tmp -> length; i++)
	{
		(tmp -> node)[i - 1] = (tmp -> node)[i];
	}
	(tmp -> node)[tmp -> length - 1] = 0;
	tmp -> length--;

	return (void*)it;
}

void Queue_Destroy(Queue* queue)
{
	int ret = 0;
        Sequeue* tmp = (Sequeue*)queue;

        if (tmp == NULL)
        {
                ret = -1;
                printf("func exec Queue_Destroy err: %d\n", ret);
		return;
        }

	if (tmp -> node != NULL)
	{
		free(tmp -> node);
	}

	free(tmp);
	return;
}

void Queue_Clear(Queue* queue)
{
	int ret = 0;
	Sequeue* tmp = (Sequeue*)queue;

        if (tmp == NULL)
        {
                ret = -1;
                printf("func exec Queue_Clear err: %d\n", ret);
                return;
        }

	if (tmp -> node != NULL)
	{
                free(tmp -> node);
        }
	tmp -> node = NULL;

	tmp -> length = 0;
	tmp -> capacity = 0;

	return;
}
