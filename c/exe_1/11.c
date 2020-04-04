#include<stdio.h>
#include<stdlib.h>

void Merge(int *L1, int *L2)
{
	int Length = sizeof(L1)/sizeof(int);
	printf("Length is %d\n", Length);
	int *mergeList = (int *)malloc(Length * sizeof(int) * 2);
	int i, j, k;
	for (i = 0, j = 0, k = 0; k < 2 * Length;)
	{
		while (i < Length && j < Length)
		{
			if (L1[i] < L2[j])
			{
				mergeList[k++] = L1[i++];
			}
			else if (L1[i] > L2[j])
			{
				mergeList[k++] = L2[j++];
			}
			else
			{
				mergeList[k++] = L1[i++];
				mergeList[k++] = L2[j++];
			}
		}
		while (i < Length && j >= Length)
		{
			mergeList[k++] = L1[i++];
		}
		while (i >= Length && j < Length)
		{
			mergeList[k++] = L2[j++];
		}
	}
	for (i = 0; i < 2 * Length; i++)
	{
		printf("mergeList[%d] : %d\n", i, mergeList[i]);
	}
}

int main()
{
	int data1[] = {1, 2, 5, 8, 10};
	int data2[] = {3, 4, 5, 9, 12};
	Merge(data1, data2);
}
