#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// 有头结点

typedef struct LNode
{
	int data;
	struct *LNode next;
}LNode, *LinkList;

bool InitLinkList(LinkList *L)
{
	LNode *NewEle = (LNode *)malloc(sizeof(LNode));
	if (NewEle == NULL)
		return false;
	L = NewEle;
	L -> next = NULL;
	return true;
}

// 按位查找
LNode * SearchEle(LinkList *L, int location)
{
	int j;
	LNode *q = L;
	if (location < 0)
		return NULL
	for (j = 0; q != NULL && j < location; j++)
	{
		q = q -> next;
	}
	return q;
}

// 按值查找
LNode * GetElem(LinkList *L, int value)
{
	LNode *q = L;
	while (q != NULL && q -> data != value)
	{
		q = q ->next;
	}
	return q;
}

// 计算表长
int length(LinkList *L)
{
	int j;
	LNode *q = L;
	for (j = 0; q -> next != NULL; j++)
	{
		q = q -> next;
	}
	return j
}

int main()
{
	LinkList L;
	InitLinkList(&L);
}
