#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// 有头结点

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

bool InitLinkList(LinkList L)
{
	printf("aaaaa");
	LNode *NewEle = (LNode *)malloc(sizeof(LNode));
	if (NewEle == NULL)
		return false;
	L = NewEle;
	L -> next = NULL;
	return true;
}

// 尾插法
LinkList ListTailsert(LinkList L)
{
	int x;
	InitLinkList(L);
	LNode *s, *r = L;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s -> data = x;
		r -> next = s;
		r = s;
		scanf("%d", &x);
	}
	r -> next = NULL;
	return L;
}

// 头插法
LinkList ListHeadsert(LinkList L)
{
	int x;
	scanf("%d", &x);
	bool result;
	// result = InitLinkList(L);
	L = (LNode *)malloc(sizeof(LNode));
	L -> next = NULL;
	LNode *s;
	while(x != 999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s -> next = L -> next;
		s -> data = x;
		L -> next = s;
		scanf("%d", &x);
	}
	return L;
}

// 遍历链表
void TraverseLinkList(LinkList L)
{
	int j;
	LNode *q = L;
	for (j = 0; q != NULL; j++)
	{
		printf("LinkList[%d]: %d\n", j, q -> data);
		q = q -> next;
	}
}

int main()
{
	LinkList L;
	InitLinkList(L);
	L = ListHeadsert(L);
	TraverseLinkList(L);
}
