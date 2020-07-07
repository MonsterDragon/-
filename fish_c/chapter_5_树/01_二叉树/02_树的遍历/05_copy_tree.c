#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct BiTNode
{
	struct BiTNode *lchild, *rchild;
	int data;
}BiTNode, *BiTree;

BiTNode* copy_tree(BiTNode* tree)
{
	if (tree == NULL)
	{
		return NULL; 
	}
	BiTNode *t1 = (BiTNode*)malloc(sizeof(BiTNode));
	t1 = tree;
	t1 -> lchild = tree -> lchild;
	t1 -> rchild = tree -> rchild;
	t1 -> data = tree -> data;
	copy_tree(tree -> lchild);
	copy_tree(tree -> rchild);
	return t1;
}

void show_tree(BiTNode* tree)
{
	if (tree == NULL)
	{
		return;
	}
	show_tree(tree -> lchild);
	printf("%d\n", tree -> data);
	show_tree(tree -> rchild);
}

int main()
{
	BiTNode t1, t2, t3, t4, t5;

	memset(&t1, 0, sizeof(BiTNode));
	memset(&t2, 0, sizeof(BiTNode));
	memset(&t3, 0, sizeof(BiTNode));
	memset(&t4, 0, sizeof(BiTNode));
	memset(&t5, 0, sizeof(BiTNode));

	t1.data = 10;
	t2.data = 20;
	t3.data = 30;
	t4.data = 40;
	t5.data = 50;

	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t2.rchild = &t5;

	show_tree(&t1);
	BiTNode *tr = copy_tree(&t1);
	show_tree(tr);
}
