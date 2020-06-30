#ifndef _MY_QUEUE_H_
#define _MY_QUEUE_H_

typedef void Queue;

Queue* Queue_Create();

void Queue_Destroy(Queue* queue);

void Queue_Clear(Queue* queue);

int Queue_Append(Queue* queue, void* item);

void* Queue_Retrieve(Queue* queue);

void* Queue_Header(Queue* queue);

int Queue_Length(Queue* queue);

int Queue_Capacity(Queue* queue);

#endif 
