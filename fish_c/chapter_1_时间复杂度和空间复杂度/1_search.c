/*
 * 问题：
 * 在一个由自然数1-1000中某些数字组成的数组中，每个数字可能出现零次或这多次
 * 设计一个算法，找出出现次数最多的数字
 * */
#include<stdio.h>
#include<stdlib.h>

struct dlist
{
	int data;
	int count;
};

// void search(int *L, int n)
void search(int L[], int n)
{
	int i, j, data;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n-i-1; j++)
		{
			if (L[j] > L[j+1])
			{
				data = L[j];
				L[j] = L[j+1];
				L[j+1] = data;
			}
		}
	}
	int max=1, acc=1;
	for (i = 1; i < n; i++)
	{
		if (L[i] == L[i-1])
		{
			acc++;
			if (acc > max)
			{
				max = acc;
			}
		}
		else
		{
			acc = 1;
		}
	}
	printf("max is %d\n", max);
}

void dsearch(struct dlist *d, int *a, int k)
{
	int i;
	int index;
	printf("sizeof a %d\n", sizeof(a));
	printf("%p\n", a);
	for (i = 0; i < k; i++)
	{
		// printf("array[%d] = %d\n", i, a[i]);
		index = a[i] - 1;
		d[index].count++;
		d[index].data = index + 1;
		// printf("index = %d, %d = %d\n", index, d[index].data, d[index].count);
	}
	int j;
	int max=0;
	int num;
	for (j = 0; j < 1000; j++)
	{
		if (d[j].count != 0)
		{
			if (max < d[j].count)
			{
				max = d[j].count;
				num = d[j].data;
			}
		}
	}
	printf("the num is %d, count is %d\n", num, max);
}

int main()
{
	int array[] = {1, 2, 3, 1, 1, 7, 3, 9, 1, 10, 6};
	search(array, sizeof(array)/sizeof(*array));
	int i;
	for (i = 0; i < 11; i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}
	printf("sizeof a is %d\n", sizeof(array));
        struct dlist c_list[1000];
	for (i = 0; i < 1000; i++)
	{
		c_list[i].count = 0;
	}
	int brray[] = {1, 2, 3, 1, 1, 7, 3, 9, 1, 10, 6};
	dsearch(c_list, brray, sizeof(brray)/sizeof(*brray));
}
