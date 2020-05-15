#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

void sort(char *or, char *new)
{
	char *from = or;
	char *to = new;
	int start = 0;
	int end = 0;

	if (from == NULL || to == NULL)
	{
		return;
	}
	end = strlen(from) - 1;
	while (from[start] != '\0' && isspace(from[start]))
		start++;
	while (isspace(from[end]))
		end--;
	while (start <= end)
	{
		*to++ = from[start];
		start++;
	}
}

int clear(char *kv, char *key, char *value, int *lenth)
{
	char *kav = kv;
	char *k = key;

	kav = strstr(kav, k);
	if (kav == NULL)
	{
		return 1;
	}
	kav = kav + strlen(k);

	kav = strstr(kav, "=");
	if (kav == NULL)
	{
		return 1;
	}
	kav += 1;

	sort(kav, value);
	*lenth = strlen(value);

	return 0;
}

int main()
{
	char *str1 = "key1  =    value1     ";
	char *buf = "key1";
	char value[128];
	int len = 0;
	int result;

	result = clear(str1, buf, value, &len);

	if (result)
	{
		printf("clear fun err:%d\n", result);
	}
	printf("value: %p\n", value);

	printf("value: %s, len: %d\n", value, len);
}
