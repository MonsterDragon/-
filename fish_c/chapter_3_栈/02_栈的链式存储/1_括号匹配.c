#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"linkstack.c"

int match(const char* str)
{
	int i = 0;
	LinkStack* stack = LinkStack_Create();
	for (i = 0; i < strlen(str); i++)
	{
		char* tmp = NULL;
		char current = str[i];
		printf("current: %c\n", current);
		switch (current)
		{
			case '(':
				LinkStack_Push(stack, &current);
				continue;
			case '{':
				LinkStack_Push(stack, &current);
				continue;
			case '[':
				LinkStack_Push(stack, &current);
				continue;
			case '<':
				LinkStack_Push(stack, &current);
				continue;
			case ')':
				tmp = (char*)LinkStack_Pop(stack);
				if (*tmp == '(')
				{
					printf("match '()'\n");	
					continue;
				}
				else
				{
					printf("Invalid code! Not match '('\n");
					return -1;
				}
			case '}':
				tmp = (char*)LinkStack_Pop(stack);
				if (*tmp == '{')
				{
					printf("match '{}'\n");	
					continue;
				}
				else
				{
					printf("Invalid code! Not match '{'\n");
					return -1;
				}
			case ']':
				tmp = (char*)LinkStack_Pop(stack);
				if (*tmp == '[')
				{
					printf("match '[]'\n");	
					continue;
				}
				else
				{
					printf("Invalid code! Not match '['\n");
					return -1;
				}
			case '>':
				tmp = (char*)LinkStack_Pop(stack);
				if (*tmp == '<')
				{
					printf("match '<>'\n");	
					continue;
				}
				else
				{
					printf("Invalid code! Not match '<'\n");
					return -1;
				}
			default:
				continue;
		}
	}
	return 0;
}

void output_func(num)
{
	if (num == 0)
	{
		printf("match successfully!\n");
	}
	else
	{
		printf("match failed!\n");
	}
}

int main()
{
	int ret = 0;
	const char* str = "include <stdio.h> int main { int a[4][4]; int (*p)[4]; p = a[0]; return 0;}";
	ret = match(str);
	output_func(ret);
}
