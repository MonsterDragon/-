#include<stdio.h>
#include<stdbool.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList *L)
{
	*L = NULL;
	return true;
}

LNode * Search(LinkList L, int n)
{
	// 无头结点
	int i = 1;
	LNode *p = L -> next;
	if (n == 0)
		return L;
	if (n < 1)
		return NULL;
	while(p != NULL && i<n)
	{
		p = p -> next;
		i++;
	}
}

int main()
{
	LinkList L;
	bool result;
	result = InitList(&L);
}
