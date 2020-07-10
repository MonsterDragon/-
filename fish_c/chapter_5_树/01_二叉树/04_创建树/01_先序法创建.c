#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

char Nil = '#';

BiTNode * Create_BiTree(BiTNode *T)
{
	char h;
	scanf("%c", &h);

	if (h == Nil)
	{
		printf("nil: %c\n", Nil);
		T = NULL;				
	}
	else
	{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		if (!T)
		{
			return NULL;
		}
		T -> data = h;
		Create_BiTree(T -> lchild);
		Create_BiTree(T -> rchild);
	}

	return T;
}

void fiorder(BiTNode *T)
{
	if (!T)
	{
		return;
	}
	printf("%c\n", T -> data);
	fiorder(T -> lchild);
	fiorder(T -> rchild);
}

int main()
{
	char str[] = {'1', '2', '3'};
	BiTNode *start = NULL;
	BiTNode *end = NULL;
	
	end = Create_BiTree(start);
	fiorder(end);
}
