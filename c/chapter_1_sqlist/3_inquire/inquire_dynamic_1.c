#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define InitSize 12

typedef struct
{
	int *data;
	int length;
	int MaxSize;
}SqList;

void InitList(SqList *L)
{
	int i;
	L -> data = (int *)malloc(InitSize * sizeof(int));
	for (i = 0; i < InitSize; i++)
	{
		L -> data[i] = 0;
	}
	L -> MaxSize = InitSize;
	L -> length = 0;
}

void IncreaseList(SqList *L, int len)
{
	int i;
	int *q = L -> data;
	L -> data = (int *)malloc((L -> MaxSize + len) * sizeof(int));
	for (i = 0; i < L -> length; i++)
	{
		L -> data[i] = q[i];
	}
	L -> MaxSize += len;
}

bool InsertList(SqList *L, int i, int n)
{
	if (L -> length == L -> MaxSize)
	{
		IncreaseList(L, 10);
	}
	if (i < 1 || i > L -> length + 1)
	{
		return false;
	}
	else
	{
		int index;
		for (index = L -> length - 1; index >= i - 1; index--)
		{
			L -> data[index + 1] = L -> data[index];
		}
		L -> data[i - 1] = n;
		L -> length++;
		return true;
	}
}

bool SubtractList(SqList *L, int i)
{
	if (L -> length < i)
	{
		printf("overtake limit!\n");
		return false;
	}
	if (i < 1)
	{
		printf("error argue!\n");
		return false;
	}
	else
	{
		int index;
		for (index = i; index <= L -> length; index++)
		{
			L -> data[index - 1] = L -> data[index];
		}
		L -> length--;
		return true;
	}
}

//int InquiryValue(SqList *L, int s)
//{
//	if (s < 1 || s > L -> length)
//		printf("wrong argus!\n");
//	else
//	{
//		return L -> data[s - 1];
//	}	
//}

bool InquiryValue(SqList L, int s, int *e)
{
	if (s < 1 || s > L.length)
	{
		printf("wrong argus!\n");
		return false;
	}
	else
	{
		*e = L.data[s - 1];
		return true;
	}
}

bool InquirySituation(SqList L, int i, int *s)
{
	int index;
	for (index = 0; index < L.length; index++)
	{
		if (L.data[index] == i)
		{
			*s = index + 1;
			return true;
		}
	}
	return false;
}

int main()
{
	int i;
	bool result;
	SqList L;
	InitList(&L);
	for (i = 0; i < L.MaxSize - 3; i++)
	{
		L.data[i] = i + 3;
	}
	L.length = L.MaxSize - 3;
	result = InsertList(&L, 3, 1000);
	if (result)
	{
		for (i = 0; i < L.MaxSize; i++)
		{
			printf("data[%d] : %d\n", i, L.data[i]);
		}
	}
	else
	{
		printf("Increase failes!\n");
	}
	result = SubtractList(&L, 8);
	if (result)
	{
		for (i = 0; i < L.MaxSize; i++)
		{
			printf("data[%d] : %d\n", i, L.data[i]);
		}
	}
	else
	{
		printf("subtract failed!\n");
	}
	bool value;
	int e;
	value = InquiryValue(L, 4, &e);
	if (value)
		printf("the 4 situation is %d\n", e);
	else
		return 0;
	int s;
	bool aa;
	aa = InquirySituation(L, 10, &s);
	if (aa)
		printf("the situation is %d\n", s);
	else
		printf("not exist!\n");
}
