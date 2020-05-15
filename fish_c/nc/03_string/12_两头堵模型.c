#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int sort(char *orstr, char *nstr)
{
	char *from = orstr;
	char *to = nstr;
	int count = 0;

	if (from == NULL || to == NULL)
	{
		return -1;
	}

	int start = 0, end = strlen(from) - 1;
	while (isspace(from[start]) && from[start] != '\0')
		start++;
	while (isspace(from[end]) && from[end] != '\0')
		end--;
	// while (start <= end)
	// {
	// 	*nstr++ = from[start];
	// 	start++;
	// }
	
	count = end - start + 1;
	strncpy(to, from + start, count);
	return 0;
}

int main()
{
	char *p = "    abcgasj    ";
	char newstr[128];
	int result;

	result = sort(p, newstr);
	if (result != 0)
	{
		printf("exec err: %d\n", result);
	}

	printf("%s\n", newstr);
}
