#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct DNode
{
	int data;
	struct DNode *next, *prior;
}DNode, *DLinkList;

DLinkList InitDLinkList(DLinkList L)
{
	DNode *q = (DNode *)malloc(sizeof(DNode));
	if (q == NULL)
		return NULL;
	L = q;
	L -> next = L;
	L -> prior = L;
	return L;
}

int main()
{
	DLinkList L;
	L = InitDLinkList(L);
}
