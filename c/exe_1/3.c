#include<stdio.h>

typedef struct
{
	int data*;
	int length;
	int MaxSize;
}SqList

//bool DeleteEle(SqList *L, int num)
//{
//	int i;
//	for (i = 0; i < L -> length; i++)
//	{
//		if (L -> data[i] == num)
//		{
//			int index = i;
//			for (index; index < L -> length - 1; index++)
//			{
//				L -> data[i] = L -> data[i + 1];
//			}
//			L -> data[length - 1] = 0;
//		}
//	}
//}

bool DeleteEle(SqList *L, int num)
{
	int i, k = 0;
	for (i = 0; i < L -> length; i++)
	{
		if (L -> data[i] == num)
		{
			k++;
		}
		else
		{
			L -> data[i - k] = L -> data[i];
		}
	}
	L -> length -= k;
}

bool DeleteEle(SqList *L, int num)
{
	int i, k = 0;
	for (i = 0; i < L -> length; i++)
	{
		if (L -> data[i] != num)
		{
			L -> data[k] = L -> data[i];
			k++;
		}
	}
	L -> length = k;
}
