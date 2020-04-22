#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize 10

struct Node
{
	int data;
	int next;
};

typedef struct
{
	int data;
	int next;
}SLinkList[MaxSize];

typedef struct 
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

int main()
{
	struct Node x;
	printf("sizeof x is %d\n", sizeof(x));

	struct Node a[MaxSize];
	printf("sizeof a is %d\n", sizeof(a));

	SLinkList b;
	printf("sizeof b is %d\n", sizeof(b));
}
