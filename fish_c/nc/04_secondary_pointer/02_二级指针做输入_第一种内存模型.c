#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *myArray[] = {"aaa", "dddd", "ccc", "bbb"};
	int num = sizeof(myArray)/sizeof(myArray[0]);

	int i, j;
	for (i = 0; i < num; i++)
	{
		printf("%s\n", myArray[i]);
	}
	// for (i = 0; i < num; i++) // 由小到大，先获得最小的，再获得最大的
	// {
	// 	for (j = i+1; j < num; j++)
	// 	{
	// 		if (strcmp(myArray[i], myArray[j]) > 0)
	// 		{
	// 			char *tmp;
	// 			tmp = myArray[i];
	// 			myArray[i] = myArray[j];
	// 			myArray[j] = tmp;
	// 		}
	// 	}
	// }
	for (i = 0; i < num; i++) // 由大到小，先获得最大的
	{
		for (j = 0; j < num-i-1; j++)
		{
			if (strcmp(myArray[j], myArray[j+1]) > 0)
			{
				char *tmp;
				tmp = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = tmp;
			}
		}
	}

	printf("排序后\n");
	for (i = 0; i < num; i++)
	{
		printf("%s\n", myArray[i]);
	}
}
