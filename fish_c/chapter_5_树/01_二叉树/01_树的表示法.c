#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// 二叉链表示法
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
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
	t2.lchild = &t4;
	t3.lchild = &t5;
}
