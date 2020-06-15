#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"circlelist.c"

typedef struct Value
{
	CircleListNode node;
	int v;
}value;

int main()
{
	int i = 0;
	CircleList *list = CircleList_Create();

	value v1;
	value v2;
	value v3;
	value v4;
	value v5;
	value v6;
	value v7;
	value v8;

	v1.v = 11;
	v2.v = 12;
	v3.v = 13;
	v4.v = 14;
	v5.v = 15;
	v6.v = 16;
	v7.v = 17;
	v8.v = 18;

	CircleList_Insert(list, &(v1.node), 0); // 头插法 
	// CircleList_Insert(list, &(v1.node), CircleList_Length(list)); // 尾插法 
	CircleList_Insert(list, &(v2.node), CircleList_Length(list)); 
	CircleList_Insert(list, &(v3.node), CircleList_Length(list)); 
	CircleList_Insert(list, &(v4.node), CircleList_Length(list)); 
	CircleList_Insert(list, &(v5.node), CircleList_Length(list)); 
	CircleList_Insert(list, &(v6.node), CircleList_Length(list)); 
	CircleList_Insert(list, &(v7.node), CircleList_Length(list)); 
	CircleList_Insert(list, &(v8.node), CircleList_Length(list)); 

	for (i = 0; i<CircleList_Length(list); i++)
	{
		value* tmp = (value*)CircleList_Get(list, i);
		printf("%d\n", tmp -> v);
	}


	// 重置游标
	CircleList_Reset(list);

	while (CircleList_Length(list) > 0)
	{
		for (i=0; i<2; i++)
		{
			CircleList_Next(list);
		}
		value* tmp = (value*)CircleList_Current(list);
		printf("%d\n", tmp -> v);
		CircleList_DeleteNode(list, (CircleListNode*)tmp);
	}
	// while (CircleList_Length(list) > 0)
	// {
	// 	value *tmp = (value *)CircleList_Delete(list, 0);
	// }

	// CircleList_Destroy(list);

	return 0;
}
