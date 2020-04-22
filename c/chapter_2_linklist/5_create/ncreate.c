#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

// 无头结点

// 尾插法
LinkList LinkTailsert(LinkList L)
{
	L = NULL;
	int x;
	L = (LNode *)malloc(sizeof(LNode));
	scanf("%d", &x);
	L -> data = x;
	L -> next = NULL;
	scanf("%d", &x);
	LNode *s = L;
	while (x != 999)
	{
		LNode *r = (LNode *)malloc(sizeof(LNode));
		r -> data = x;
		s -> next = r;
		s = r;
		scanf("%d", &x);
	}
	s -> next = NULL;
	return L;
}

// 头插法
LinkList LinkHeadlsert(LinkList L)
{
	L = (LNode *)malloc(sizeof(LNode));
	int x;
	scanf("%d", &x);
	L -> data = x;
	L -> next = NULL;
	scanf("%d", &x);
	while (x != 999)
	{
		LNode *r = (LNode *)malloc(sizeof(LNode));
		r -> data = x;
		r -> next = L;
		L = r;
		scanf("%d", &x);
	}
	return L;
}

void TraverseList(LinkList L)
{
	int j;
	LNode *q = L;
	for (j = 1; q != NULL; j++)
	{
		printf("L[%d] : %d", j , q -> data);
		q = q -> next;
	}
}

int main()
{
	LinkList L;
	// L = LinkHeadsert(L);
	L = LinkTailsert(L);
	TraverseList(L);
}
