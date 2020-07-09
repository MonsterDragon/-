#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// int NUM = 0;

typedef struct  BiTNode
{
	int value;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 判断左右节点是否存在的if语句块可以放置在任意的位置
// 三种递归的本质：所有的叶子都会被访问只是访问的顺序不同
void countleaf(BiTNode *T, int *sum)
{
	if (T)
	{
		if (!T -> lchild && !T -> rchild)
		{
			(*sum)++;		
		}
		countleaf(T -> lchild, sum);
		countleaf(T -> rchild, sum);
	}
}

// 求树的深度
int Depth(BiTNode *T)
{
	int depleft = 0;
	int depright = 0;
	int deptval = 0;

	if (T == NULL)
	{
		return deptval;
	}

	depleft = Depth(T -> lchild);

	depright = Depth(T -> rchild);

	deptval = 1 + (depleft > depright ? depleft : depright);

	return deptval;
}

int main()
{
	BiTNode t1, t2, t3, t4, t5;
	
	memset(&t1, 0, sizeof(BiTNode));
	memset(&t2, 0, sizeof(BiTNode));
	memset(&t3, 0, sizeof(BiTNode));
	memset(&t4, 0, sizeof(BiTNode));
	memset(&t5, 0, sizeof(BiTNode));

	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t2.rchild = &t5;

	int sum = 0;

	countleaf(&t1, &sum);
	printf("%d\n", sum);
	printf("%d\n", Depth(&t1));
}
