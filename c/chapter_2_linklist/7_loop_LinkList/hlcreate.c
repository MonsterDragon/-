#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

LNode * InitLinkList(LinkList L)
{
	LNode *q = (LNode *)malloc(sizeof(LNode));
	if (q == NULL)
		return false;
	L = q;
	L -> next = NULL;
	return L;
}

// 判断节点p是否为循环单链表的表尾节点
bool isTail(LinkList *L, LNode *p)
{
	if (p -> next == L)
		return true;
	else
		return false;
}

int main()
{
	LinkList L;
	L = InitLinkList(L);
}
