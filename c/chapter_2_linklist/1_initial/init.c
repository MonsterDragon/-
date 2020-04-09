#include<stdio.h>
#include<stdbool.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList; // Linklist表示为单链表

// LinkList 强调这是一个单链表
// LNode 强调这是一个结点

LNode * GetElem(LinkList L, int i)
{
	int j = 1;
	LNode *p = L -> next;
	if(i == 0)
		return L;
	if(i < 1)
		return NULL;
	while(p!=NULL && j<i)
	{
		p = p -> next;
		j++;
	}
	return p;
}

bool InitLinkList(LinkList *L)
{
	*L = NULL;
	return true;
}

bool Empty(LinkList L)
{
	return (L == NULL);
}

int main()
{
	LinkList L;	
	printf("%p\n", L);
	LNode M;
	printf("%d\n", M.data);
	InitLinkList(&L);
	printf("%p\n", L);
	bool result;
	result = Empty(L);
	if (result)
		printf("successful\n");
	else
		printf("failed\n");
}
