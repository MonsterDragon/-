#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int clean(char *orstr, char *nstr)
{
	char *from = orstr;
	char *to = nstr;
	int i = 0;
	printf("aaaaafffff: %p\n", to);

	if (orstr == NULL || nstr == NULL)
	{
		printf("wrong address!\n");
		return 0;
	}

	while (*from != '\0')
	{
		if (*from != ' ')
		{
			*to++ = *from++;
		}
		else
		{
			from++;
		}
	}

	return 1;
}

int main()
{
	char *nstr = "    abcdefgdddd    ";
	char newstr[strlen(nstr)];
	int result;
	printf("nstr: %p\n", nstr);
	printf("newstr: %p\n", newstr);

	result = clean(nstr, newstr);
	
	if (result != 0)
	{
		printf("newstr: %s\n", newstr);
	}
	else
	{
		printf("clean string error!\n");
	}
}
