#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"dlinklist.h"

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode *censor;
	int length;
}TDLinkList;

DLinkList *DLinkList_Create()
{
	int ret;
	TDLinkList *tlist = (TDLinkList *)malloc(sizeof(TDLinkList));
	
	if (tlist == NULL)
	{
		ret = -1;
		printf("exec func DLinkList_Create err: %d\n", ret);
		return;
	}

	tlist -> header.next = NULL;
	tlist -> header.pre = NULL;
	tlist -> censor = NULL;

	return tlist;
}

void DLinkList_Destroy(DLinkList *list)
{
	int ret = 0;
	TDLinkList *tlist = (TDLinkList *)list;

	if (tlist == NULL)
	{
		ret = -1;
		printf("exec func DLinkList_Destroy err: %d\n", ret);
		return;
	}

	free(tlist);
	tlist = NULL;
}

void DLinkList_Clear(DLinkList *list)
{
	int ret = 0;
        TDLinkList *tlist = (TDLinkList *)list;
        
        if (tlist == NULL)
        {       
                ret = -1;
                printf("exec func DLinkList_Clear err: %d\n", ret);
                return;
        }

	tlist -> header.next = NULL;
	tlist -> header.pre = NULL;
	tlist -> censor = NULL;
	tlist -> length = 0;
}

int DLinkList_Length(DLinkList *list)
{
	int ret = 0, leng = 0;
        TDLinkList *tlist = (TDLinkList *)list;

        if (tlist == NULL)
        {
                ret = -1;
                printf("exec func DLinkList_Length err: %d\n", ret);
                return;
        }

	leng = tlist -> length;
	return leng;	
}

int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos)
{
	int ret = 0, i = 0;
        TDLinkList *tlist = (TDLinkList *)list;
	DLinkListNode *current = &(tlist -> header);
	DLinkListNode *next = NULL;

        if (tlist == NULL || pos < 0 || pos > tlist -> length)
        {
                ret = -1;
                printf("exec func DLinkList_tlist err: %d\n", ret);
                return ret;
        }

	for (i = 0; i < pos && (current -> next != NULL); i++)	
	{
		current = current -> next;
	}

	next = current -> next;
	node -> next = next;
	current -> next = node;

	if (tlist -> length == 0)
	{
		ret = 0;
		tlist -> length++;
		node -> pre = NULL;
		tlist -> censor = node;
		return ret;
	}

	if (pos == 0)
	{
		ret = 0;
		tlist -> length++;
		next -> pre = node;
		node -> pre = NULL;
		return ret;
	}

	if (pos == tlist -> length)
	{
		ret = 0;
		tlist -> length++;
		node -> pre = current;
		return ret;
	}
		
	tlist -> length++;
	next -> pre = node;
	node -> pre = current;
	return ret;
}

DLinkListNode* DLinkList_Get(DLinkList *list, int pos)
{
	int ret = 0, i = 0;
        TDLinkList *tlist = (TDLinkList *)list;
	DLinkListNode *current = &(tlist -> header);

        if (tlist == NULL || pos < 0 || pos > tlist -> length - 1)
        {
                ret = -1;
                printf("exec func DLinkList_Get err: %d\n", ret);
                return;
        }

	for (i = 0; i < pos && (current -> next != NULL); i++)
	{
		current = current -> next;
	}

	return current -> next;
}

DLinkListNode* DLinkList_Delete(DLinkList *list, int pos)
{
	int ret = 0, i = 0;
        TDLinkList *tlist = (TDLinkList *)list;
        DLinkListNode *current = &(tlist -> header);
        DLinkListNode *node = NULL;
        DLinkListNode *next = NULL;

	if (tlist -> length == 0)
	{
		ret = -2;
		printf("exec func DLinkList_Delete err: %d\n", ret);
		return;
	}

        if (tlist == NULL || pos < 0 || pos > tlist -> length - 1)
        {
                ret = -1;
                printf("exec func DLinkList_Delete err: %d\n", ret);
                return;
        }

	for (i = 0; i < pos && (current -> next != NULL); i++)
        {
                current = current -> next;
        }

	node = current -> next;
	next = node -> next;
	if (tlist -> censor == node)
	{
		tlist -> censor = next;
	}

	if (tlist -> length == 1)
	{
		tlist -> length--;
		// current -> next = NULL;
		tlist -> censor = NULL;
		return node;
	}

	if (pos == tlist -> length - 1)
	{
		tlist -> length--;
		current -> next = NULL;
		return node;
	}

	if (pos == 0)
	{
		tlist -> length--;
		current -> next = next;
		next -> pre = NULL;
		return node;
	}

	tlist -> length--;
	current -> next = next;
	next -> pre = current;

	return node;
}

// add
DLinkListNode* DLinkList_DeleteNode(DLinkList *list, DLinkListNode* node)
{
	int ret = 0, i = 0;
	TDLinkList *tlist = (TDLinkList *)list;
	DLinkListNode *current = &(tlist -> header);
	DLinkListNode* tmp = NULL;

	if (tlist == NULL || node == NULL)
        {
                ret = -1;
                printf("exec func DLinkList_DeleteNode err: %d\n", ret);
                return;
        }

	for (i = 0; i < tlist -> length -1; i++)
	{
		if (current -> next == node)
		{
			tmp = current -> next;
			break;
		}
		current = current -> next;
	}

	if (tmp != NULL)
	{
		DLinkList_Delete(list, i);
	}

	return tmp;
}

DLinkListNode* DLinkList_Reset(DLinkList *list)
{
	int ret = 0;
        TDLinkList *tlist = (TDLinkList *)list;

	if (tlist == NULL)
        {
                ret = -1;
                printf("exec func DLinkList_Reset err: %d\n", ret);
                return;
        }

	tlist -> censor = tlist -> header.next;

	return tlist -> censor;
}

DLinkListNode* DLinkList_Current(DLinkList *list)
{
	int ret = 0;
        TDLinkList *tlist = (TDLinkList *)list;

        if (tlist == NULL)
        {
                ret = -1;
                printf("exec func DLinkList_Current err: %d\n", ret);
                return;
        }

	return tlist -> censor;
}

DLinkListNode* DLinkList_Next(DLinkList *list)
{
	int ret = 0;
        TDLinkList *tlist = (TDLinkList *)list;
	DLinkListNode* tmp = NULL;

        if (tlist == NULL || tlist -> censor == NULL)
        {
                ret = -1;
                printf("exec func DLinkList_Next err: %d\n", ret);
                return;
        }
	
	tmp = tlist -> censor;
	tlist -> censor = tmp -> next;
	return tmp;	
}

DLinkListNode* DLinkList_Pre(DLinkList *list)
{
	int ret = 0;
        TDLinkList *tlist = (TDLinkList *)list;
	DLinkListNode* tmp = NULL;

        if (tlist == NULL || tlist -> censor == NULL)
        {
                ret = -1;
                printf("exec func DLinkList_Pre err: %d\n", ret);
                return;
        }
	
	tmp = tlist -> censor;
	tlist -> censor = tmp -> pre;
	return tmp;	
}
