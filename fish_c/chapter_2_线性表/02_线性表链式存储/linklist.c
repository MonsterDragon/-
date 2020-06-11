#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"linklist.h"

// 规定：pos表示从零开始的位置
// 链表默认是有头结点的
// header 0 1 2 3
// 跳length的长度的次数恰好到最后一位
typedef struct _tag_LinkList
{	
	LinkListNode header;
	int length;
}TLinkList;

LinkList * LinkList_Create()
{
	int ret;
	TLinkList *tlist = NULL; // 为了全局通用要放到堆区
	tlist = (TLinkList *)malloc(sizeof(TLinkList));
	if (tlist == NULL)
	{
		ret = -1;
		printf("func LinkList_Create() err:%d\n", ret);
		return NULL;
	}
	// memset(tlist, 0, sizeof(TLinkList));
	tlist -> length = 0;
	(tlist -> header).next = NULL;
	return (LinkList *)tlist;
}

// int Node_Destroy(LinkListNode *node, int length)
// {
// 	printf("node: %p\n", node);
// 	printf("length: %d\n", length);
// 	if (L < length && node -> next != NULL)
// 	{
// 		LinkListNode *node = node -> next;
// 		L++;
// 		printf("%d\n", L);
// 		printf("bb\n");
// 		Node_Destroy(node, length);
// 	}
// 	free(node);
// 	printf("%d\n", L);
// 	node = NULL;
// 	return 0;
// }
// 
// void LinkList_Destroy(LinkList *list)
// {
// 	int ret;
// 	// 使用递归函数进行destroy
// 	TLinkList *tlist = (TLinkList *)list;
// 	if (tlist == NULL)
// 	{
// 		ret = -1;
// 		printf("func LinkList_Destroy() err:%d\n", ret);
// 		return;
// 	}
// 	LinkListNode *tmp = &(tlist -> header);
// 	ret = Node_Destroy(tmp, tlist -> length);
// 	if (ret != 0)
// 	{
// 		printf("func Node_Destroy() err:%d\n", ret);
// 		return;
// 	}
// 	return;
// }

void LinkList_Destroy(LinkList *list)
{
	int ret;
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

// 将链表恢复为初始状态
void LinkList_Clear(LinkList *list)
{
	int ret;
	TLinkList *tlist = (TLinkList *)list;	
	if (tlist == NULL)
	{
		ret = -1;
		printf("func LinkList_Clear() err:%d\n", ret);
		return;
	}
	(tlist -> header).next = NULL;
	(tlist -> length) = 0;
	// memset(tlist, 0, sizeof(TLinkList));
	return;
}

int LinkList_Length(LinkList *list)
{
	int ret, len;
	TLinkList *tlist = (TLinkList *)list;
	if (tlist == NULL)
        {
                ret = -1;
                printf("func LinkList_Clear() err:%d\n", ret);
                return;
        }
	len = tlist -> length;
	return len;
}

// int LinkList_Length(LinkList *list)
// {
// 	int ret, len = 0;
// 	TLinkList *tlist = (TLinkList *)list;
// 	LinkListNode *tnode = NULL;
// 
// 	if (tlist == NULL)
// 	{
// 		ret = -1;
// 		printf("func LinkList_Length() err:%d\n", ret);
// 		return;
// 	}
// 
// 	if (tlist -> header.next == NULL)
// 	{
// 		len = 0;
// 		return len;		
// 	}
// 
// 	tnode = &(tlist -> header);
// 	while (tnode -> next != NULL)
// 	{
// 		tnode = tnode -> next;
// 		len++;
// 	}
// 
// 	return len;
// }

int LinkList_Insert(LinkList *list, LinkListNode *node, int pos)
{
	int ret, len = 0;
	TLinkList *tlist = (TLinkList *)list;
	if (tlist == NULL || node == NULL)
	{
		ret = -1;
		printf("func LinkList_Insert() err:%d\n", ret);
		return ret;
	}
	if (pos < 0 || pos > tlist -> length + 1)
	{
		ret = -2;
		printf("func LinkList_Insert() err:%d\n", ret);
		return ret;
	}

	// 头插法
	if (pos == 0)
	{
		node -> next = tlist -> header.next;
		tlist -> header.next = node;
		(tlist -> length)++;
	}

	// 尾插法
	else if (pos >= tlist -> length)
	{
		// while (len < tlist -> length)
		// {
		// 	tmp = tmp -> next;
		// 	len++
		// }
		LinkListNode *tmp = &(tlist -> header);
		for (len = 0; len < tlist -> length; len++)
		{
			tmp = tmp -> next;
		}
		tmp -> next = node;
		tlist -> length++;
	}

	// 插入
	// pos是从0开始的
	// pos = n ，跳n次，到达n-1的位置
	else
	{
		len = 0;
		LinkListNode *tmp = &(tlist -> header);
		for (len = 0; len < pos && (tmp -> next != NULL); len++)
		{
			tmp = tmp -> next;
		}
		node -> next = tmp -> next;
		tmp -> next = node;
		tlist -> length++;
	}

	return 0;
}

LinkListNode * LinkList_Get(LinkList *list, int pos)
{
	int ret, len = 0;
	TLinkList *tlist = (TLinkList *)list;
	LinkListNode *tnode = NULL;
	LinkListNode *tmp = &(tlist -> header); // tmp辅助指针变量是重点，表明条约多次之后所达到的位置

	if (tlist == NULL || pos < 0 || pos > tlist -> length - 1)
	{
		ret = -1;
		printf("func LinkList_Length() err:%d\n", ret);
		return;
	}

	for (len; len < pos && (tmp -> next != NULL); len++)
	{
		tmp = tmp -> next;
	}
	tnode = tmp -> next;

	return tnode;
}

LinkListNode * LinkList_Delete(LinkList *list, int pos)
{
	int ret, len = 0;
	TLinkList *tlist = (TLinkList *)list;
	LinkListNode *tnode = NULL;
	LinkListNode *tmp = &(tlist -> header);

	if (tlist == NULL || pos < 0 || pos >= tlist -> length)
	{
		ret = -1;
		printf("func LinkList_Delete() err:%d\n", ret);
		return;
	}

	for (len; len < pos && (tmp -> next != NULL); len++)
	{
		tmp = tmp -> next;
	}
	if (tmp -> next == NULL)
	{
		ret = -2;
		printf("func LinkList_Delete() err:%d\n", ret);
		return;
	}
	tnode = tmp -> next;
	tmp -> next = tnode -> next;
	tlist -> length--;
	
	return tnode;
}

