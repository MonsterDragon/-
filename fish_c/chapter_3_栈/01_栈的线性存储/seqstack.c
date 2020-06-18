#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"seqstack.h"

typedef struct _tag_SeqStack
{
	int length;
	int capacity;
	unsigned long *node;
}TSeqStack;

SeqStack* SeqStack_Create(int capacity)
{
	int ret = 0;

	TSeqStack* tstack = (TSeqStack*)malloc(sizeof(TSeqStack));

	if (tstack == NULL)
	{
		ret = -1;
		printf("func SeqStack_Create err: %d\n", ret);
		return;
	}

	memset(tstack, 0, sizeof(TSeqStack));
	tstack -> capacity = capacity;
	tstack -> length = 0;
	tstack -> node = (unsigned long*)malloc(sizeof(unsigned long) * capacity);

	if (tstack -> node == NULL)
        {
                ret = -2;
                printf("func SeqStack_Create err: %d\n", ret);          
                return;
        }

	return tstack;
}

void SeqStack_Destory(SeqStack* stack)
{
	int ret = 0;
	TSeqStack* tstack = (TSeqStack*)stack;

	if (tstack == NULL)
	{
		ret = -1;
                printf("func SeqStack_Destroy err: %d\n", ret);
                return;	
	}

	free(tstack);
	tstack = NULL;

	return;
}

void SeqStack_Clear(SeqStack* stack)
{
	int ret = 0;
	TSeqStack* tstack = (TSeqStack*)stack;

	if (tstack == NULL)
        {
                ret = -1;
                printf("func SeqStack_Clear err: %d\n", ret);
                return;
        }

	tstack -> length = 0;
	
	return;
}

int SeqStack_Push(SeqStack* stack, void* item)
{
	int ret = 0, i = 0;
        TSeqStack* tstack = (TSeqStack*)stack;

	if (tstack == NULL)
        {
                ret = -1;
                printf("func SeqStack_Push err: %d\n", ret);
                return ret;
        }

	if (item == NULL)
        {
                ret = -2;
                printf("func SeqStack_Push err: %d\n", ret);
                return ret;
        }
	
	if (tstack -> length < tstack -> capacity)
	{
		tstack -> node[tstack -> length] = (unsigned long)item; 
	}

	if (tstack -> length == tstack -> capacity)
	{
		ret = -3;
		printf("func SeqStack_Push err: %d\n", ret);
		return ret;
	}

	tstack -> length++;

	return 0;
}

// 弹出第一个元素
void* SeqStack_Pop(SeqStack* stack)
{
	int ret = 0, i = 0;
        TSeqStack* tstack = (TSeqStack*)stack;
	unsigned long tmp = NULL;

	if (tstack == NULL)
        {
                ret = -1;
                printf("func SeqStack_Pop err: %d\n", ret);
		return;
        }

	if (tstack -> length == 0)
	{
		ret = -2;
                printf("func SeqStack_Pop err: %d\n", ret);
                return;
	}

	if (tstack -> length > 0)
	{
		tmp = tstack -> node[tstack -> length - 1];
		tstack -> node[tstack -> length - 1] = 0;
	}

	tstack -> length--;

	return (void*)tmp;
}

void* SeqStack_Top(SeqStack* stack)
{
	int ret = 0;
	TSeqStack* tstack = (TSeqStack*)stack;
        unsigned long tmp = NULL;

	if (tstack == NULL)
        {
                ret = -1;
                printf("func SeqStack_Top err: %d\n", ret);
                return;
        }

        if (tstack -> length == 0)
        {
                ret = -2;
                printf("func SeqStack_Top err: %d\n", ret);
                return;
        }

	if (tstack -> length > 0)
        {
                tmp = tstack -> node[tstack -> length - 1];
        }

	return (void*)tmp;
}

int SeqStack_Size(SeqStack* stack)
{
	int ret = 0, leng = 0;
	TSeqStack* tstack = (TSeqStack*)stack;

	if (tstack == NULL)
        {
                ret = -1;
                printf("func SeqStack_Top err: %d\n", ret);
                return;
        }

	leng = tstack -> length;

	return leng;
}

int SeqStack_Capacity(SeqStack* stack)
{
	int ret = 0, capacity = 0;
	TSeqStack* tstack = (TSeqStack*)stack;

	if (tstack == NULL)
        {
                ret = -1;
                printf("func SeqStack_Top err: %d\n", ret);
                return;
        }
	
	capacity = tstack -> capacity;

	return capacity;
}
