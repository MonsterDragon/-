#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct DNode
{
	int data;
	struct DNode *next, *prior;
}DNode, *DLinkList;

DLinkList InitDLinkList(DLinkList L)
{
	DNode *q = (DNode *)malloc(sizeof(DNode));
	if (q == NULL)
		return NULL;
	L = q;
	L -> next = L;
	L -> prior = L;
	return L;
}

// 判断循环双链表是否为空
bool Empty(DLinkList L)
{
	if (L -> next == L)
		return true;
	else
		return false;
}

// 判断结点p是否为循环双链表的标为节点
bool Tail(DLinkList L, DNode *q)
{
	if (q -> next == L)
		return true;
	else
		return false;
}
int main()
{
	DLinkList L;
	L = InitDLinkList(L);
}
