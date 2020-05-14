#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

void clean(char *ostr, char *nstr)
{
	int start = 0;
	int end = 0;

	char *from = ostr;
	char *to = nstr;

	end = strlen(from) - 1;

	while (isspace(from[start]) && from[start] != '\0')
		start++;
	while (isspace(from[end]) && from[end] != '\0')
		end--;
	while (start <= end)
	{
		*to = from[start];
		start++;
		to++;
	}
	*to = '\0';
}

int main()
{
	char *orstr = "    ascskashck    ";
	char newstr[strlen(orstr) + 1];
	
	clean(orstr, newstr);
	printf("%s\n", newstr);
}
