#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int sort(char **myp1, int num1, char (*myp2)[30], int num2, char ***myp3, int *num3)
{
	char **p3 = NULL;
	p3 = (char **)malloc(sizeof(char *) * (num1 + num2));
	if (p3 == NULL)
	{
		return -1;
	}

	int i, j;
	int tmplen;
	for (i=0; i<num1; i++)
	{
		tmplen = strlen(myp1[i]) + 1;
		p3[i] = (char *)malloc(sizeof(char) * tmplen);
		strcpy(p3[i], myp1[i]); // char *strcpy( char *to, const char *from );
	}
	for (j=0; j<num2; j++, i++)
	{
		tmplen = strlen(myp2[j]) + 1;
		p3[i] = (char *)malloc(sizeof(char) * tmplen);
		strcpy(p3[i], myp2[j]);
	}

	*num3 = num1 + num2;
	char *tmp;
	// 排序
	for (i=0; i<*num3; i++)
	{
		for (j=i+1; j<*num3; j++)
		{
			if (strcmp(p3[i], p3[j]) > 0) //  int strcmp( const char *str1, const char *str2 );
			{
				tmp = p3[i];
				p3[i] = p3[j];
				p3[j] = tmp;
			}
		}
	}

	// 间接赋值
	*myp3 = p3;

	return 0;
}

void sortfree(char ***p3, int num)
{
	int i;

	if (p3 == NULL)
	{
		printf("error\n");
		return;
	}
	for (i=0; i<num; i++)
	{
		free((*p3)[i]);
	}
	free(*p3);
}

int main()
{
	char *p1[] = {"aaaaaaa", "cccccccc", "bbbbbbbb"}; // 指针数组
	char buf[10][30] = {"1111111", "22222222", "333333333"}; // 二维数组的元素个数必须要有
	char **p3 = NULL;

	int len1, len2, len3, ret;
	len1 = sizeof(p1) / sizeof(*p1);
	len2 = 3;

	ret = sort(p1, len1, buf, len2, &p3, &len3);
	if (ret != 0)
	{
		printf("sort err : %d\n", ret);
		return ret;
	}

	int i=0;
	for (i=0; i<6; i++)
	{
		printf("%s\n", p3[i]);
	}

	sortfree(&p3, len3);
}
