#include<stdio.h>
#include<stdbool.h>

typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode, *LinkList;

Lnode * GetElem(LinkList L, int i)
{
	int j = 1;
	Lnode *p = L -> next;
	if(i == 0)
	{
		return L;
	}
	if(i < 0)
	{
		return NULL; 
	}
	while(p != NULL && j<i)
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

int main()
{
	LinkList L;
	bool result;
	result = InitLinkList(&L);
}
