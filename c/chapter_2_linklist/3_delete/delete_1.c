#include<stdio.h>
#include<stdbool.h>
#include<stdlid.h>

typedef struct LNode
{
	int data;
	struct LNode * next;
}LNode, *LinkList;

bool InitLinkList(*L)
{
	L = (LNode *)malloc(sizeof(LNode *));
	if (L == NULL)
		return false;
	L -> next = NULL;
	return true;
}

// 有头结点 时间复杂度是O(n)
bool ListDelete(LinkList *L, int i, int *e)
{
	if (i < 1)
		return false;
	int j;
	LNode *q = L
	for (j = 0; q -> next != NULL && j < i - 1; j++)
	{
		q = q -> next;
	}
	if (q == NULL)
		return false;
	if (q -> next == NULL)
		return false;
	*e = q -> next -> data;
	q -> next = q -> next -> next;
	free(q)
	return true;
}

// 无头结点 时间复杂度是O(n)
bool ListDelete(LinkList *L, int i, int *e)
{
	int j;
	LNode *q = L;
	if (i < 1)
		return false;
	if (i == 1)
	{
		if (q == NULL)
			return false;
		L = q -> next;
		*e = q -> data;
		return true;
	}
	else
	{
		for (j = 1; q -> next != NULL && j < i-1; j++)
		{
			q = q -> next;
		}
		if (q == NULL)
			return false;
		if (q -> next == NULL)
			return false;
		*e = q -> data;
		q -> next = q -> next -> next;
		free(q);
		return false;
	}
}

// 指定节点删除（该节点不是最后一个节点）
bool DeleteNode(LNode *p)
{
	if (p == NULL)
		return false;
	p -> data = p -> next -> data;
	p -> next = p -> next -> next;
	free(p -> next);
	return true;
}

int main()
{
	// 有头结点
	LinkList L;
	InitLinkList(&L);
	int e;
	ListDelete(&L, i, &e)
}
