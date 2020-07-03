#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct BPTNode
{
	int data;
	// long int parentPosition; // 指向父节点的指针
	int parentPosition; // 数组下标
	char LRTag; // 左右孩子标志域
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[100]; // 顺序表存储
	int num_node; // 节点数目
	int root; // 根节点的位置 // 注意此域存储的是父节点在数组的下标
}BPTree;

int main()
{
	BPTree tree;
	tree.num_node = 4;
	tree.root = 0;

	tree.nodes[0].parentPosition = -1;
	tree.nodes[0].data = 0;

	tree.nodes[1].parentPosition = 0;
	tree.nodes[1].LRTag = '1';
	tree.nodes[1].data = 10;

	tree.nodes[2].parentPosition = 0;
        tree.nodes[2].LRTag = '2';
        tree.nodes[2].data = 20;

	tree.nodes[3].parentPosition = 1;
        tree.nodes[3].LRTag = '1';
        tree.nodes[3].data = 30;
}
