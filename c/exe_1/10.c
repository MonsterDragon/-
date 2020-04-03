#include<stdio.h>
#include<stdbool.h>

bool Reversal(int *L, int start, int end)
{
	int tmp, i;
	for (i = 0; i < (end - start + 1) / 2; i++)
	{
		tmp = L[start + i];
		L[start + i] =  L[end - i];
		L[end - i] = tmp;
	}
	return true;
}

int main()
{
	int data[] = {1, 2, 3, 4, 5, 6, 7 ,8};
	Reversal(data, 0, 3);
	Reversal(data, 4, 7);
	Reversal(data, 0, 7);
	int i;
	for (i = 0; i < 8; i++)
	{
		printf("data[%d] : %d\n", i, data[i]);
	}
}
