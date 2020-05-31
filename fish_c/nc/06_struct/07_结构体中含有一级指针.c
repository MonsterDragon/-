#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct Teacher
{
	char name[64];
	char *aliasname;
	int age;
	int id;
};

int createTeacher(struct Teacher **p, int num)
{
	if (p == NULL)
	{
		return -1;
	}
	*p = (struct Teacher *)malloc(sizeof(struct Teacher) * num);
	return 1;
}

void freemem(struct Teacher *p, int num)
{
	int i;
	for (i=0; i<num; i++)
	{
		free(p[i].aliasname);
	}
	free(p);
}

int main()
{
	struct Teacher *t1;
	int num = 3;
	int ret;

	ret = createTeacher(&t1, num);
	if (ret != 1)
	{
		printf("malloc error!\n");
		return -1;
	}
	int i;
	for (i=0; i<num; i++)
	{
		printf("\nPlease enter aliasname: ");
		t1[i].aliasname = (char *)malloc(sizeof(char) * 128);
		scanf("%s", t1[i].aliasname);
	}
	for (i=0; i<num; i++)
	{
		printf("%s\n", t1[i].aliasname);
	}
	freemem(t1, num);
}
