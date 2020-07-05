#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;	
}BiTNode, *BiTree;

void midOrder(BiTNode *root)
{
	if (root == NULL)
	{
		return;
	}

	midOrder(root -> lchild);
	
	printf("%d\n", root -> data);

	midOrder(root -> rchild);
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
	t3.lchild = &t5;

	midOrder(&t1);
}
