#ifndef _MY_LINKQUEUE_H_
#define _MY_LINKQUEUE_H_

typedef void LinkQueue;

typedef struct _tag_LinkQueueNode
{
	struct _tag_LinkQueueNode* next;
}LinkQueueNode;

LinkQueue* LinkQueue_Create();

void LinkQueue_Destroy(LinkQueue* queue);

void LinkQueue_Clear(LinkQueue* queue);

int LinkQueue_Append(LinkQueue* queue, void* item);

void* LinkQueue_Retrieve(LinkQueue* queue);

void* LinkQueue_Header(LinkQueue* queue);

int LinkQueue_Length(LinkQueue* queue);

#endif //_MY_LINKQUEUE_H_
