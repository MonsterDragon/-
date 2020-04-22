#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 无头结点

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

bool InitLinkList(LinkLIst *L)
{
	L  = NULL;
	return true;
}

// 按位查找
LNode * LocateElem(LinkList *L, int location)
{
	if (location < 1)
		return NULL;
	LNode *q = L;
	int j;
	for(j = 1; q != NULL && j < location; j++)
	{
		q = q -> next;
	}
	return q;
}

// 按值查找
LNode * GetElem(LinkList *L, int value)
{
	LNode *q = L;
	while(q != NULL && q -> data != value)
	{
		q = q -> next;
	}
	return q;
}

// 计算长度
int length(LinkList *L)
{
	int j;
	LNode *q = L;
	for (j = 1; q -> next != NULL; j++)
	{
		q = q -> next;
	}
	return j;
}

int main()
{
	LinkList L;
	InitLinkList(&L);
}
