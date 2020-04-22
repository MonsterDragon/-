#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
// 包含头结点

typedef struct LNode
{
	int data;
	struct LNode * next;
}LNode, *LinkList;

bool InitLinkList(LinkList *L)
{
	LNode * NewEle = (LNode *)malloc(sizeof(LNode));
	if (LNode == NULL)
		return false;
	L = NewEle;
	L -> next = NULL;
}

// 按位查找
LNode * LocateElem(LinkList *L, int location)
{
	if (location < 0)
		return NULL;
	LNode *q = L;
	int j;
	for (j = 0; q != NULL && j < location; j++)
	{
		q = q -> next;
	}
	return q;
}

// 按值查找
LNode * GetElem(LinkList *L, int value)
{
	// int j;
	LNode *q = L -> next;
	// for (j = 0; q -> next != NULL && q -> data != value; j++)
	// {
	// 	q = q -> next;
	// }
	while (q != NULL && q -> data != value) // q != NULL的目的在于遍历全部链表后未找到值，q的值是NULL。而q -> next != NULL在遍历全部链表未找到值，q的值是链表最后一个节点的地址
	{
		q = q -> next;
	}
	return q;
}

// 求表长
int length(LinkList *L)
{
	int j;
	LNode *q = L;
	for (j = 0; q -> next != NULL; j++)
	{
		q = q -> next;
	}
	return j;
}

int main()
{
	LinkList L;
	InitLinkList(&L);
	SearchEle(&L, 4);
}
