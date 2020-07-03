#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
	struct BiTNode *parent;
}BiTNode, *BiTree;

int main()
{
	BiTNode t1, t2, t3, t4, t5;

	t1.data = 10;
	t2.data = 20;
	t3.data = 30;
	t4.data = 40;
	t5.data = 50;

	t1.lchild = &t2;
	t1.rchild = &t3;
	t1.parent = NULL;

	t2.parent = &t1;
	t2.lchild = &t4;
	t2.rchild = NULL;

	t3.parent = &t1;
	t3.lchild = &t5;
	t3.rchild = NULL;

	t4.parent = &t2;
	
	t5.parent = &t3;
}
