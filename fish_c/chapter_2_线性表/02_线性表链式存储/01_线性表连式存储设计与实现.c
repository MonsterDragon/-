#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"linklist.c"

typedef struct Teacher
{
	LinkListNode node;
	int age;
	char name[64];
}teacher;

int main()
{
	int ret, len, i;
	teacher *tmp;
	LinkList *list = NULL;
	list = LinkList_Create();

	if (list == NULL)
	{
		ret = -1;
		return ret;
	}

	len = LinkList_Length(list);

	teacher t1;
	teacher t2;
	teacher t3;
	teacher t4;
	teacher t5;
	t1.age = 22;
	t2.age = 23;
	t3.age = 24;
	t4.age = 25;
	t5.age = 26;
	
	ret = LinkList_Insert(list, (LinkListNode *)&(t1.node), 0);
	ret = LinkList_Insert(list, (LinkListNode *)&(t2.node), 0);
	ret = LinkList_Insert(list, (LinkListNode *)&(t3.node), 0);
	ret = LinkList_Insert(list, (LinkListNode *)&(t4.node), 0);
	ret = LinkList_Insert(list, (LinkListNode *)&(t5.node), 0);
	// 插入节点
	// ret = LinkList_Insert(list, (LinkListNode *)&(t1), 0);
	// ret = LinkList_Insert(list, (LinkListNode *)&(t2), 0);
	// ret = LinkList_Insert(list, (LinkListNode *)&(t3), 0);
	// ret = LinkList_Insert(list, (LinkListNode *)&(t4), 0);
	// ret = LinkList_Insert(list, (LinkListNode *)&(t5), 0);

	// 遍历
	for (i=0; i<LinkList_Length(list); i++)
	{
		tmp = (teacher *)LinkList_Get(list, i);
		if (tmp == NULL)
		{
			ret = -2;
			return ret;
		}
		printf("tmp -> age: %d\n", tmp -> age);
	}

	// 删除链表
	while (LinkList_Length(list) > 0)
	{
		tmp = (teacher *)LinkList_Delete(list, 0);
		if (tmp == NULL)
		{
			ret = -3;
			return ret;
		}
		printf("tmp -> age: %d\n", tmp -> age);
	}

	printf("aa\n");
	LinkList_Destroy(list);

	return 0;
nkList_Length(list)}
