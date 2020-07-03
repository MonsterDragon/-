#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int main()
{
	BiTNode *t1, *t2, *t3, *t4, *t5;
	t1 = (BiTNode*)malloc(sizeof(BiTNode));
	t2 = (BiTNode*)malloc(sizeof(BiTNode));
	t3 = (BiTNode*)malloc(sizeof(BiTNode));
	t4 = (BiTNode*)malloc(sizeof(BiTNode));
	t5 = (BiTNode*)malloc(sizeof(BiTNode));
	
	t1 -> lchild = t2;
	t1 -> rchild = t3;
	t2 -> lchild = t4;
	t3 -> lchild = t5;
}
