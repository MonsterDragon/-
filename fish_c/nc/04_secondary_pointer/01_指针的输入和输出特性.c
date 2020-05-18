#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// 指针做输出，被调用函数分配内存
int getMem(char **p1, int *len1, char **p2, int *len2)
{
	if (p1 == NULL || p2 == NULL)
	{
		return 0;
	}
	char *tmp1 = NULL;
	tmp1 = (char *)malloc(1024);
	strcpy(tmp1, "aascsacds");
	int *tlen1 = len1;
	*tlen1 = strlen(tmp1);
	*p1 = tmp1;

	char *tmp2 = NULL;
	tmp2 = (char *)malloc(1024);
	strcpy(tmp2, "cahksjchak");
	int *tlen2 = len2;
	*tlen2 = strlen(tmp2);
	*p2 = tmp2;
	return 1;
}

void free_mem(char **tmp)
{
	char *p = NULL;
	p = *tmp;
	free(p);
	*tmp = NULL;
}

int main()
{
	char *p1 = NULL;
	int len1 = 0;

	char *p2 = NULL;
	int len2 = 0;

	int ret = 0;
	ret = getMem(&p1, &len1, &p2, &len2);
	printf("p1: %s\n", p1);
	printf("p2: %s\n", p2);

	free_mem(&p1);
	free_mem(&p2);
}
