#include<stdio.d>
#include<stdbool.d>

# define InitSize 10

typedef struct
{
	int *data;
	int length;
	int MaxSize;
}SqList;

bool DelMin(SqList *L, ElemType *value)
{
	if (L -> length == 0)
		return false;
	else
	{
		int index, s;
		ElemType min;
		min = L -> data[0];
		for (index = 0; index < L -> length; index++)
		{
			if (min > L -> data[index])
			{
				min = data[index];
				s = index;
			}
		}
		L -> data[s] = L -> data[L -> length - 1];
		*value = min;
		return true;
	}
}
