#include<stdio.h>
#include<stdlib.h>

// 此方法的时间复杂度为O(n)，空间复杂度也为O(n)

void Merge_1(int *L1, int *L2, int Length)
{
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
	printf("mid num %d is %d\n", (Length*2-1)/2, mergeList[(Length*2-1)/2]);
}

// 此方法的时间复杂度是O(n/2) = O(n)，空间复杂度是O(1)
Merge_2(int *L1, int *L2, int n)
{
	int i, j, k, num;
	for (i = 0, j = 0, k = 0; k <= (n*2-1)/2; )
	{
		while (L1[i] < L2[j])
		{
			num = L1[i++];
			k++;
		}
		while (L1[i] > L2[j])
		{
			num = L2[j++];
			k++;
		}
		while (L1[i] == L2[j])
		{
			num = L1[i++];
			j++;
			k += 2;
		}
	}
	printf("mid num %d is %d\n", (n*2-1)/2, num);
}

int main()
{
	int data1[] = {1, 2, 5, 8, 10};
	int data2[] = {3, 4, 5, 9, 12};
	int length = sizeof(data1) / sizeof(int);
	// Merge_1(data1, data2, length);
	Merge_2(data1, data2, length);
}
