#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTNode * Create_pre_mid(char *pre, char *mid, int len)
{

	// 遍历先序遍历的数组，第一个值就是root
	BiTNode *root = (BiTNode*)malloc(sizeof(BiTNode));
	root -> data = pre[0];
	root -> lchild = NULL;
	root -> rchild = NULL;
	
	// 在中序遍历中找到左、右子树
	char *midorder = mid;
	int leftlen = 0;
	while (*midorder != root -> data && leftlen < len)
	{
		midorder++;
		leftlen++;
	}

	if (*midorder != root -> data)
	{
		return NULL;
	}

	if (leftlen > 0)
	{
		root -> lchild = Create_pre_mid(pre + 1, mid, leftlen);
	}

	if (len - leftlen - 1 > 0)
	{
		root -> rchild = Create_pre_mid(pre + leftlen + 1, midorder + 1, len - leftlen - 1);
	}

	return root;
}

void check_param(char *pre, char *mid, int len)
{
	if (pre == NULL || mid == NULL || len <= 0)
	{
		printf("param is wrong\n");
		return ;
	}
}

void pre_order(BiTNode *T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%c\n", T -> data);
	pre_order(T -> lchild);
	pre_order(T -> rchild);
}

int main()
{
	char pre[] = {'A', 'D', 'E', 'B', 'C', 'F'};
	char mid[] = {'D', 'E', 'A', 'C', 'F', 'B'};
	
	check_param(pre, mid, 7);
	BiTree tree = Create_pre_mid(pre, mid, 7);
	pre_order(tree);
}
