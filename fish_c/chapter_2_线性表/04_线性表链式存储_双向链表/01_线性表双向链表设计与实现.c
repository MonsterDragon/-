#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"dlinklist.c"

typedef struct Value
{
	DLinkListNode node;
	int v;
}value;

int main()
{
	int i;
	DLinkList* list = DLinkList_Create();

	value* tmp = NULL;
	value v1, v2, v3, v4, v5;

	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;

	DLinkList_Insert(list, (DLinkListNode*)&v1, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v2, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v3, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v4, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&v5, DLinkList_Length(list));

	for (i = 0; i < DLinkList_Length(list); i++)
	{
		tmp = (value*)DLinkList_Get(list, i);
		printf("%d\n", tmp -> v);
	}

	printf("\n");
	
	tmp = (value*)DLinkList_Delete(list, DLinkList_Length(list) - 1);
	tmp = (value*)DLinkList_Delete(list, 0);

	for (i = 0; i < DLinkList_Length(list); i++)
	{
		tmp = (value*)DLinkList_Next(list);
		printf("%d\n", tmp -> v);
	}

	printf("\n");

	DLinkList_Reset(list);
	tmp  = (value*)DLinkList_Next(list);
	printf("%d\n", tmp -> v);

	tmp  = (value*)DLinkList_Current(list);
	printf("%d\n", tmp -> v);

	DLinkList_DeleteNode(list, (DLinkListNode*)tmp);
	tmp  = (value*)DLinkList_Current(list);
        printf("%d\n", tmp -> v);
	
	DLinkList_Pre(list);
	tmp  = (value*)DLinkList_Current(list);
	printf("%d\n", tmp -> v);

	printf("Length: %d\n", DLinkList_Length(list));

	DLinkList_Destroy(list);
}
