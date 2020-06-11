#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist.h"

typedef struct _tag_seqlist
{
	int length;
	int capacity;
	unsigned long *node; // 指针指向传入节点所组成的数组的内存空间 结构体中套一级指针
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	int ret = -1;
	TSeqList *tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		printf("func SeqList_Create() err:%d \n", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(tmp));

	// 根据capacity的大小分配node
	tmp -> node = (unsigned long *)malloc(sizeof(unsigned long *) * capacity);
	if (tmp -> node == NULL)
	{
		printf("func SeqList_Create() err:%d \n", ret);
		return NULL;
	}
	tmp -> capacity = capacity;
	tmp ->length = 0;
	return tmp;	
}

void SeqList_Destroy(SeqList* list)
{
	int ret;
	if (list == NULL)
	{
		ret = -1;
		printf("func SeqList_Destroy err: \"add is empty\" %d\n", ret);
		return;
	}
	TSeqList *tlist = (TSeqList *)list;
	if (tlist == NULL)
	{
		ret = -2;
		printf("func SeqList_Destroy err: \"pointer change failed\" %d\n", ret);
		return;
	}
	free(tlist -> node);
	if (*(tlist -> node) != 0)
	{
		ret = -3;
		printf("func SeqList_Destroy err: \"free node failed\" %d\n", ret);
		return;
	}
	free(tlist);
	if (tlist -> capacity != 0)
	{
		ret -3;
		printf("func SeqList_Destroy err: \"free list failed\" %d\n", ret);
		return;
	}
	tlist = NULL;
}

void SeqList_Clear(SeqList* list)
{
	int ret;
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)list;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func SeqList_Clear err: \"list is empty\" %d\n", ret);
		return;
	}
	tlist -> length = 0;
	if (tlist != 0)
	{
		ret = -2;
		printf("func SeqList_Clear err: \"clear failed\" %d\n", ret);
		return;
	}
}

int SeqList_Length(SeqList* list)
{
	int length, ret;
	TSeqList *tlist = (TSeqList *)list;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func SeqList_Length err: \"list is empty\" %d\n", ret);
		return ret;
	}
	length = tlist -> length;
	return length;
}

int SeqList_Capacity(SeqList* list)
{
	int capacity, ret;
	TSeqList *tlist = (TSeqList *)list;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func SeqList_Length err: \"list is empty\" %d\n", ret);
		return ret;
	}
	capacity = tlist -> capacity;
	return capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int ret, capacity, length, p, i;
	TSeqList *tlist = (TSeqList *)list;
	// unsigned long tnode = (unsigned long)node;
	p = pos;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func SeqList_Insert err: \"list is empty\" %d\n", ret);	
		return ret;
	}
	if (node == NULL)
	{
		ret = -1;
		printf("func SeqList_Insert err: \"SeqListNode is empty\" %d\n", ret);
		return ret;
	}
	capacity = tlist -> capacity;
	length = tlist -> length;
	if (length == capacity)
	{
		ret = -2;
		printf("func SeqList_Insert err: \"length is equal capacity\" %d\n", ret);	
		return ret;
	}
	if (p < 0 || p > capacity - 1)
	{
		ret = -3;
		printf("func SeqList_Insert err: \"position is error\" %d\n", ret);
                return ret;
	}
	// 位置是空用尾插法或头插法
	// 头插法 --> 所有的元素向后移动一位
	else if (p == 0)
	{
		if (tlist -> length  == 0)
		{
			(tlist -> node)[0] = (unsigned long)node;
			tlist -> length++;
			return 0;
		}
		for (i=sizeof(tlist -> node)-1; i>=0; i--)
		{
			(tlist -> node)[i+1] = (tlist -> node)[i];
		}
		(tlist -> node)[0] = (unsigned long)node;
		(tlist -> length)++;
	}
	else if (p+1 >= tlist -> length+1 && p+1 < tlist -> capacity)
	{
		for (i=length; i<p; i++)
		{
			(tlist -> node)[i] = 0;
		}
		(tlist -> node)[i] = (unsigned long)node;
		(tlist -> length) = p+1;
	}
	// 尾插法 --> 在最后添加一位元素
	// else if (p == NULL)
	// {
	// 	(tlist -> node)[length] = tnode;
	// 	(tlist -> length)++;
	// }
	else
	{
		for (i=sizeof(tlist -> node)-1; i>p-1; i--)
		{
			(tlist -> node)[i+1] = (tlist -> node)[i];
		}
		(tlist -> node)[p] = (unsigned long)node;
		(tlist -> length)++;
	}
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos) // pos和length及capacity代表相同的长度 pos = length = capacity = 10 长度相同
{
	int ret;
	SeqListNode *tnode;
	TSeqList *tlist = (TSeqList *)list;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func SeqList_Get err: \"list is empty\" %d\n", ret);	
		return;
	}
	if (pos > tlist -> length || pos<1)
	{
		ret = -2;
		printf("func SeqList_get err: \"position is out of range\" %d\n", ret);
		return;
	}
	tnode = (SeqListNode *)((tlist -> node)[pos-1]);
	
	return tnode;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	int ret, i;
	TSeqList *tlist = (TSeqList *)list;
	if (tlist == NULL)
	{
		ret = -1;
		printf("func SeqList_Delete err: \"list is empty\" %d\n", ret);	
		return;
	}
	if (pos == 0)
	{
		ret = -2;
		printf("func SeqList_Delte err: \"pos is empty\" %d\n", ret);
		return;
	}
	if (pos < 1 || pos > tlist -> length)
	{
		ret = -3;
		printf("func SeqList_Delte err: \"pos is out of range\" %d\n", ret);
		return;
	}
	for (i=pos-1; i<tlist->length-1; i++)
	{
		(tlist -> node)[i] = (tlist -> node)[i+1];
	}
	tlist -> length--;
	return tlist;
}
