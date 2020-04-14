#include<stdio.h>
#include<stdbool.h>

typedef struct Lnode
{
	int data;
	struct Lnode *next; 
} Lnode, *LinkList;

// 不带头结点
bool InitLinkList(LinkList *L)
{
	return (L == NULL);
}

// 带头结点
bool InitLinkList(LinkList *L)
{
	L = (Lnode *)malloc(sizeof(Lnode));
	if (L==NULL)
		return false;
	L -> next = NULL;
	return true;
}

Lnode * SearchEle(LinkList L, int i)
{
	int j = 1;
	Lnode *q = L -> next;
	if (i == 0)
	{
		return q;
	}
	else if (i < 1)
	{
		return NULL;
	}
	while (q != NULL && j < i)
	{
		q = q -> next;
		j++;
	}
}

int main()
{
	LinkList L;
	bool result;
	InitLinkList(&L);
}
