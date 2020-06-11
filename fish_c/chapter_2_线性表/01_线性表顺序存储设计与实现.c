#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist_my.c"

typedef struct Teacher
{
	int age;
	char name[64];
} Teacher;

/* 
#ifndef  __MY_SEQLIST_H__ 
#define __MY_SEQLIST_H__
typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(int capacity);

void SeqList_Destroy(SeqList* list);

void SeqList_Clear(SeqList* list);

int SeqList_Length(SeqList* list);

int SeqList_Capacity(SeqList* list);

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

SeqListNode* SeqList_Get(SeqList* list, int pos);

SeqListNode* SeqList_Delete(SeqList* list, int pos);


#endif  //__MY_SEQLIST_H__

*/

int main()
{
	SeqList *list = NULL;

	list = SeqList_Create(10);
	if (list == NULL)
	{
		printf("func SeqList_Create() ret: %d\n", -1);
		return -1;
	}

	Teacher t1, t2, t3, t4, t5;
	t1.age = 22;
	t2.age = 23;
	t3.age = 24;
	t4.age = 25;
	t5.age = 26;

	int ret;
	ret = SeqList_Insert(list, (SeqListNode *)&t1, 0); // 头插法
	ret = SeqList_Insert(list, (SeqListNode *)&t2, 0); // 头插法
	ret = SeqList_Insert(list, (SeqListNode *)&t3, 0); // 头插法
	ret = SeqList_Insert(list, (SeqListNode *)&t4, 0); // 头插法
	ret = SeqList_Insert(list, (SeqListNode *)&t5, 0); // 头插法

	int i = 0;
	// while (i<5)
	// {
	// 	printf("list[%d]: %d\n", i, list[i].age);
	// }
	for (i=1; i<SeqList_Length(list)+1; i++)
	{
		Teacher *tmp = (Teacher *)SeqList_Get(list, i);
		printf("list[%d]: %d\n", i, tmp->age);
	}
}
