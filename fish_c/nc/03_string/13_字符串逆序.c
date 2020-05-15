#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int reverse(char *old, char *nstr)
{
	char *from = old;
	char *to = nstr;
	char transition;

	if (from == NULL, to == NULL)
	{
		return -1;
	}

	int start = 0, end = strlen(from) - 1;
	printf("%d\n", end);
	while (start < end)
	{
		transition = from[start];
		from[start] = from[end];
		from[end] = transition;
		start++;
		end--;
	}
	return 0;
}

int main()
{
	char str[64] = "asacacscddg";
	char new[128];
	int result;
	
	result = reverse(str, new);
	if (result != 0)
	{
		printf("exec reverse err: %d\n", result);
	}
	printf("new: %s\n", str);
}
