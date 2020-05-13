#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int sort(char *org, char *st, int *count)
{
	int ret = 0;
	if (org == NULL || st == NULL || count == NULL)
	{
		ret = -1;
		printf("org == NULL || st == NULL || count == NULL\n");
		return ret;		
	}
	char *sub = org;
	char *t = st;
	int *cc = count;
	// int n = 0;
	while(sub = strstr(sub, t))
	{
		// n++;
		(*cc)++;
		// *cc++;
		sub += strlen(t);
	}
	// *count = n;
	return ret;
}

int main()
{
	char *aa = "123asha123akshajshc";
	int co = 0;
	char *ss = "123";
	int nn = 0;

	nn = sort(aa, ss, &co);

	if (nn == 0)
	{
		printf("co: %d\n", co);
	}
	else
	{
		printf("exec sort error!\n");
	}
}
