#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"circlelist.h"

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode *censor;
	int length;
}TCircleList;

CircleList* CircleList_Create()
{
	int ret;
	TCircleList *tlist = (TCircleList *)malloc(sizeof(TCircleList));

	if (tlist == NULL)
	{
		ret = -1;
		printf("func CircleList_Create err: %d\n", ret);
		return;
	}

	tlist -> header.next = NULL;
	tlist -> censor = NULL;
	tlist -> length = 0;

	return tlist;
}

void CircleList_Destroy(CircleList* list)
{
	int ret;
	if (list == NULL)
	{
		ret = -1;
                printf("func CircleList_Destroy err: %d\n", ret);
                return;
	}

	free(list);
	list == NULL;

	return;
}

void CircleList_Clear(CircleList* list)
{
        int ret;
        if (list == NULL)
        {
                ret = -1;
                printf("func CircleList_Clear err: %d\n", ret);
                return;
        }

	TCircleList *tlist = (TCircleList *)list;
	tlist -> header.next = NULL;
	tlist -> censor = NULL;

	return;
}

int CircleList_Length(CircleList* list)
{
        int ret;
        if (list == NULL)
        {
                ret = -1;
                printf("func CircleList_Length err: %d\n", ret);
                return;
        }

	TCircleList *tlist = (TCircleList *)list;
	int len = tlist -> length;

	return len;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	int ret, i;
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode *current = &(tlist -> header);
        if (list == NULL || node == NULL)
        {
                ret = -1;
                printf("func CircleList_Insert err: %d\n", ret);
                return;
        }

	if (pos < 0 || pos > tlist -> length)
	{
                ret = -2;
                printf("func CircleList_Insert err: %d\n", ret);
                return;
	}

	for (i = 0; i < pos && (current -> next != NULL); i++)
	{
		current = current -> next;
	}

	node -> next = current -> next;
	current -> next = node;

	if (tlist -> length == 0)
	{
		tlist -> censor = &(tlist -> header);
	}

	tlist -> length++;

	if (pos == 0)
	{
		CircleListNode *last = CircleList_Get(list, tlist -> length - 1);
		last -> next = node;
	}

	return 0;
}

CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	int i, ret;
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode *current = &(tlist -> header);
	if (list == NULL || pos < 0)
	{
		ret = -1;
                printf("func CircleList_Get err: %d\n", ret);
                return;
	}

	for (i = 0; i < pos && (current -> next != NULL); i++)
	{
		current = current -> next ;
	}
	
	return current -> next;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	int i, ret;
        TCircleList *tlist = (TCircleList *)list;
	CircleListNode *current = &(tlist -> header);
	CircleListNode *last = NULL;
	CircleListNode *tmp;

	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func CircleList_Delete err: %d\n", ret);
                return;
	}

	for (i = 0; i < pos && (current -> next != NULL); i++)
	{
		current = current -> next;
	}

	tmp = current -> next;

	if (pos == 0)
	{
		last = CircleList_Get(list, tlist -> length - 1);
	}

	current -> next = tmp -> next;
	tlist -> length--;

	if (last != NULL)
	{
		last -> next = (tmp -> next);
	}

	if (tmp == tlist -> censor)
	{
		tlist -> censor = tmp -> next;
	}
	
	if (tlist -> length == 0)
	{
		tlist -> censor = NULL;
		(tlist -> header).next = NULL;
	}
	
	return tmp;
}

//add

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	int ret, i;
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode *current = &(tlist -> header);
	CircleListNode *tmp;

	if (list == NULL|| node == NULL)
	{
		ret = -1;
                printf("func CircleList_DeleteNode err: %d\n", ret);
                return;
	}

	for (i = 0; i < tlist -> length - 1 && (current -> next != NULL); i++)
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
		CircleList_Delete(list, i);
	}

	return NULL;
}

CircleListNode* CircleList_Reset(CircleList* list)
{
	int ret;
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode *current = NULL;

	if (list == NULL)
	{
		ret = -1;
                printf("func CircleList_Reset err: %d\n", ret);
                return;	
	}
	
	tlist -> censor = tlist -> censor -> next;
	current = tlist -> censor;

	return current;
}

CircleListNode* CircleList_Current(CircleList* list)
{
	int ret;
        TCircleList *tlist = (TCircleList *)list;

        if (list == NULL)
        {
                ret = -1;
                printf("func CircleList_Current err: %d\n", ret);
                return;
        }

	return tlist -> censor;
}

CircleListNode* CircleList_Next(CircleList* list)
{
	int ret;
        TCircleList *tlist = (TCircleList *)list;
	CircleListNode *tmp = NULL;

        if (list == NULL)
        {
                ret = -1;
                printf("func CircleList_Current err: %d\n", ret);
                return;
        }
	tmp = tlist -> censor;
	tlist -> censor = tlist -> censor -> next;
	
	return tmp;
}
