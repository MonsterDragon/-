#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

void give(char **str1, int *len1, char **str2, int *len2)
{
	*str1 = (char *)malloc(100);
	*str2 = (char *)malloc(100);
	// strcpy(*str1, "abababab");
	// strcpy(*str2, "bcbcbcbc");
	*str1 = "aaaaaa";
	*str2 = "bbbbbb";
	*len1 = 8;
	*len2 = 8;
}

int main()
{
	int len1=0, len2=0;
	char *str1=NULL, *str2=NULL;
	give(&str1, &len1, &str2, &len2);
	printf("str1: %s, len1: %d, str2: %s, len2: %d\n", str1, len1, str2, len2);
}
