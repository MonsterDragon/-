#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"linkstack.h"

typedef struct _tag_LinkStack
{
	LinkStackNode header;
	int length;
}tLinkStack;

// 业务结构体
typedef struct _tag_LinkStacktnode
{
	LinkStackNode node;
	int value;
}stacknode;

LinkStack* LinkStack_Create() 
{
	int ret = 0;
	tLinkStack *tstack = (tLinkStack*)malloc(sizeof(tLinkStack));

	if (tstack == NULL)
	{
		ret = -1;
		printf("func LinkStack_Create exec err: %d\n", ret);
		return;
	}

	(tstack -> header).next = NULL;
	tstack -> length = 0;

	return tstack;
}
 
void LinkStack_Destroy(LinkStack* stack)
{
        int ret = 0;
        tLinkStack* tstack = (tLinkStack*)stack;

        if (tstack == NULL)
        {
                ret = -1;
                printf("func LinkStack_Destroy exec err: %d\n", ret);
                return;
        }
	
	LinkStack_Clear(stack);

        free(tstack);
        tstack = NULL;

        return;
}
 
void LinkStack_Clear(LinkStack* stack) 
{
	int ret = 0;
	tLinkStack *tstack = (tLinkStack*)malloc(sizeof(tLinkStack));
	LinkStackNode* current = &(((tLinkStack*)stack) -> header);

	if (tstack == NULL)
	{
		ret = -1;
		printf("func LinkStack_Clear exec err: %d\n", ret);
		return;
	}

	// clear栈，需要把栈中的所有元素全部free
	
	int i = 0, j = 0;
	for (i = tstack -> length; i > 0; i--)
	{
		for (j = 0; j < i - 1 && (current -> next != NULL); j++)
		{
			current = current -> next;
		}
		free(current -> next);
	}

	(tstack -> header).next = NULL;
	tstack -> length = 0;

	return;
}
 
int LinkStack_Push(LinkStack* stack, void* item)
{
	stacknode* tstack = (stacknode*)malloc(sizeof(stacknode));
	memset(tstack, 0, sizeof(stacknode));
	(tstack -> node).next = NULL;
	(tstack -> value) = *(int*)item;

	int ret = 0;
	LinkStackNode* current = &(((tLinkStack*)stack) -> header);

	if (stack == NULL)
	{
		ret = -1;
		printf("func LinkStack_Push exec err: %d\n", ret);
		return ret;
	}

	// 采用头插法
	(tstack -> node).next = current -> next;
	current -> next = (LinkStackNode*)(&(tstack -> node));
	((tLinkStack*)stack) -> length++;

	return 0;
}
 
void* LinkStack_Pop(LinkStack* stack) 
{
	int ret = 0;
	LinkStackNode* current = &(((tLinkStack*)stack) -> header);

	if (stack == NULL)
	{
		ret = -1;
		printf("func LinkStack_Pop exec err: %d\n", ret);
		return NULL;
	}

	if (current -> next == NULL)
	{
		ret = -2;
		printf("func LinkStack_Pop exec err: %d\n", ret);
		return NULL;
	}

	LinkStackNode *tmp = current -> next;
	current -> next = tmp -> next;
	((tLinkStack*)stack) -> length--;

	void* v = &(((stacknode*)tmp) -> value);
	// 弹出一个元素，该元素所对应的地址free
	free(tmp);

	return v;
}
 
void* LinkStack_Top(LinkStack* stack) 
{
	int ret = 0, leng = 0;
	tLinkStack* tstack = (tLinkStack*)stack;
	LinkStackNode* current = &(((tLinkStack*)tstack) -> header);

	if (tstack == NULL)
	{
		ret = -1;
		printf("func LinkStack_Top exec err: %d\n", ret);
		return NULL;
	}

	if (current == NULL)
	{
		ret = -2;
		printf("func LinkStack_Top exec err: %d\n", ret);
		return NULL;
	}

	stacknode* tmp = (stacknode*)current -> next;
	void *v = &(tmp -> value);

	return v;
}
 
int LinkStack_Size(LinkStack* stack)
{
	int ret = 0, leng = 0;
	tLinkStack *tstack = (tLinkStack*)stack;
	
	if (tstack == NULL)
	{
		ret = -1;
		printf("func LinkStack_Size exec err: %d\n", ret);
		return ret;
	}

	leng = tstack -> length;

	return leng;
}
