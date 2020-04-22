#include<stdio.h>
#include<stdbool.h>

typedef struct LNode
{
	int data;
	struct Lnode *next;
} LNode, *LinkList;

// 初始化无头结点
bool InitLinkList(LinkList *L)
{
	*L = NULL;
	return true;
}

// 初始化有头结点
bool InitLinkList(LinkList *L)
{
	L = (LNode *)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L -> next = NULL;
	return true;
}

// 有头结点
LNode * SearchEle(LinkList L, int i)
{
	int j = 1;
	LNode * q = L;
	if (i == 0)
		return q;
	if (i < 1)
		return NULL;
	q = q -> next
	while (q != NULL && j < i)
	{
		q = q -> next;
		j++;
	}
}

// 有头结点 i 表示位序
bool InsertEle(LinkList L, int i, int digital)
{
	int j;
	LNode *q = L;
	if (i < 1)
		return false;
	for (j = 0; q != NULL && j < i-1; j++ )
	{
		q = q -> next;
	}
	// if (q == NULL)
	// 	return false; // i值不合法
	// LNode *newEle = (LNode *)malloc(sizeof(LNode));
	// newEle -> data = digital;
	// newEle -> next = q -> next;
	// q -> next = newEle;
	// return true;
	InsertNextNode(q, digital);
}

// 无头结点 i 表示位序
bool InsertEle(LinkList L, int i, int digital)
{
	int j;
	LNode q = L;
	if (i < 1)
		return false;
	if (i == 1)
	{
		LNode *NewEle = (LNode *)malloc(sizeof(LNode));
		NewEle -> data = digital;
		NewEle -> next = L;
		L = NewEle;
	}
	else
	{
		for (j = 1; q != NULL && j < i-1; j++)
		{
			q -> next;
		}
		if (q == NULL)
			return false;
		LNode *NewEle = (LNode *)malloc(sizeof(LNode));
		if (NewEle == NULL)
			return false;
		NewEle -> data = digital;
		NewEle -> next = q -> next;
		q -> next = NewEle;
		return true;
	}
	return true;
}

// 指定节点的后查操作
bool InsertNextNode(LNode *p, int digital)
{
	if (p == NULL)
		return false;
	LNode *NewEle = (LNode *)malloc(sizeof(LNode));
	if (LNode == NULL)
		return false;
	NewEle -> next = p -> next;
	p -> next = NewEle;
	NewEle -> data = digital;
	return true;
}

// 指定节点的前插操作 时间复杂度是O(n)
bool InsertPriorNode(LinkList L, LNode *p, int digital)
{
	if (p == NULL)
		return false;
	int j;
	LNode *q = L;
	while (q -> next != NULL && q -> next != p)
	{
		q = q -> next;
	}
	if (q -> next == NULL)
	{
		printf("there is no node as p\n");
		return false;
	}
	else
	{
		LNode *NewEle = (LNode *)malloc(sizeof(LNode *));
		if (NewEle == NULL)
			return false;
		NewEle -> next = p;
		q -> next = NewEle;
		NewEle -> data = digital;
		return true;
	}
}

// 指定节点的前插操作 时间复杂度是O(1)
bool InsertPriorNode(LNode *p, int digital)
{
	if (p == NULL)
		return false;
	LNode *NewEle = (LNode *)malloc(sizeof(LNode *));
	if (NewEle == NULL)
		return false;
	NewEle -> data = p -> data;
	p -> data = digital;
	NewEle -> next = p -> next;
	p -> next = NewEle;
	return true;
}

int main()
{
	bool result;
	LinkList L;
	int data = 10;
	result = InitLinkList(&L);
	result = InsertEle(L, 2, data);
}
