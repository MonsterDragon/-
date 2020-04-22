#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct DNode
{
	int data;
	struct DNode *prior, *next;
}DNode, *DLinkList;

// 带头结点

// bool InitDLinkList(DLinkList L)
// {
// 	L = (DNode *)malloc(sizeof(DNode));
// 	printf("%p", L);
// 	if (L == NULL)
// 		return false;
// 	// L -> prior = NULL;
// 	L -> next = NULL;
// 	return true;
// }

DLinkList InitDLinkList(DLinkList L)
{
	L = (DNode *)malloc(sizeof(DNode));
        if (L == NULL)
                return NULL;
	L -> next = L;
	L -> prior = L;
        return L;
}

// 在p节点之后插入s节点
bool InsertNextDNode(DNode *p, DNode *s)
{
	if (p == NULL || s == NULL)
		return false;
	s -> next = p -> next;
	if (p -> next != NULL)
	{
		p -> next -> prior = s;
	}
	p -> next = s;
	s -> prior = p;
	return true;
}

// 删除p结点的后继结点
bool DeleteNextDNode(DNode *p)
{
	if (p -> next == NULL)
		return false;
	if (p == NULL)
		return false;
	DNode *q = p -> next;
	p -> next = p -> next -> next;
	if (q -> next != NULL)
		p -> next -> prior = p;
	free(q);
	return true;
}

// 销毁双链表
void DestroyList(DLinkList L)
{
	while (L -> next != NULL)
	{
		DeleteNextDNode(L);
	}
	free(L);
	L = NULL;
}

// 创建双链表
DLinkList CreateDNode(DLinkList L)
{
	int x;
	scanf("%d", &x);
	DNode *o = L;
	while (x != 999)
	{
		DNode *q = (DNode *)malloc(sizeof(DNode));
		L -> next = q;
		q -> prior = L;
		L = q;
		L -> data = x;
		scanf("%d", &x);
	}
	L -> next = NULL;
	return o;
}

// 遍历双链表
bool TraverseDLinkList(DLinkList L)
{
	int i = 1;
	if (L == NULL)
		return false;
	while (L -> next != NULL)
	{
		L = L -> next;
		printf("DLinkList[%d] : %p\n", i, L);
		printf("DLinkList[%d] : %d\n", i, L -> data);
		i++;
	}
	return true;
}

int main()
{
	DLinkList L;
	L = InitDLinkList(L);
	printf("%p\n", L);
	L = CreateDNode(L);
	printf("%p\n", L);
	TraverseDLinkList(L);
	DestroyList(L);
}
