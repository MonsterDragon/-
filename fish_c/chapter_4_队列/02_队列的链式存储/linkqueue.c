#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"linkqueue.h"

typedef struct LinkQueue
{
	LinkQueueNode header;
	int length;
}TLinkQueue;

typedef struct queuenode
{
        LinkQueueNode node;
        int value;
}QueueNode; // 业务节点

LinkQueue* LinkQueue_Create()
{
	int ret = 0;
	
	TLinkQueue* lqueue = (TLinkQueue*)malloc(sizeof(TLinkQueue));
	if (lqueue == NULL)
	{
		ret = -1;
		printf("func LinkQueue_Create exec err: %d\n", ret);
		return NULL;
	}

	memset(lqueue, 0, sizeof(TLinkQueue));

	(lqueue -> header).next = NULL;
	lqueue -> length = 0;

	return lqueue;
}

void LinkQueue_Destroy(LinkQueue* queue)
{
	int ret = 0;

	TLinkQueue* squeue = (TLinkQueue*)queue;
	
        if (squeue == NULL)
        {
                ret = -1;
                printf("func LinkQueue_Destroy exec err: %d\n", ret);
                return;
        }

	free(squeue);
	return;
}

void LinkQueue_Clear(LinkQueue* queue)
{
	int ret = 0;

	TLinkQueue* squeue = (TLinkQueue*)queue;
	if (squeue == NULL)
        {
                ret = -1;
                printf("func LinkQueue_Clear exec err: %d\n", ret);
                return;
        }

	(squeue -> header).next = NULL;
	squeue -> length = 0;

	return;
}

int LinkQueue_Append(LinkQueue* queue, void* item)
{
	int ret = 0;

        TLinkQueue* squeue = (TLinkQueue*)queue;
	LinkQueueNode* current = &(squeue -> header);
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
	tmp -> value = *((int*)item);

        if (squeue == NULL || item == NULL)
        {
                ret = -1;
                printf("func LinkQueue_Append exec err: %d\n", ret);
                return ret;
        }

	if (squeue -> length == 0)
	{
		current -> next = (LinkQueueNode*)tmp;
		squeue -> length++;
		printf("%d\n", *(int*)item);
		return 0;
	}

	int i = 0;
	for (i = 0; i < (squeue -> length); i++)	
	{
		current = current -> next;
	}
	current -> next = (LinkQueueNode*)tmp;
	squeue -> length++;

	return 0;
}

void* LinkQueue_Retrieve(LinkQueue* queue)
{
	int ret = 0;

        TLinkQueue* squeue = (TLinkQueue*)queue;
        LinkQueueNode* current = &(squeue -> header);

	if (squeue == NULL)
        {
                ret = -1;
                printf("func LinkQueue_Retrieve exec err: %d\n", ret);
                return NULL;
        }

	if (current -> next == NULL)
	{
		ret = -2;
		printf("func LinkQueue_Retrieve exec err: %d\n", ret);
                return NULL;
	}

	QueueNode* tmp = (QueueNode*)current -> next;
	current -> next = (tmp -> node).next;
	squeue -> length--;
	
	return (void*)(&(tmp -> value));
}

void* LinkQueue_Header(LinkQueue* queue)
{
	int ret = 0;

        TLinkQueue* squeue = (TLinkQueue*)queue;
        LinkQueueNode* current = &(squeue -> header);

        if (squeue == NULL)
        {
                ret = -1;
                printf("func LinkQueue_Header exec err: %d\n", ret);
                return NULL;
        }

        if (current -> next == NULL)
        {
                ret = -2;
                printf("func LinkQueue_Header exec err: %d\n", ret);
                return NULL;
        }

	return &(((QueueNode*)current -> next) -> value);
}

int LinkQueue_Length(LinkQueue* queue)
{
	int ret = 0;

        TLinkQueue* squeue = (TLinkQueue*)queue;

	if (squeue == NULL)
        {
                ret = -1;
                printf("func LinkQueue_Length exec err: %d\n", ret);
                return ret;
        }

	return squeue -> length;
}
