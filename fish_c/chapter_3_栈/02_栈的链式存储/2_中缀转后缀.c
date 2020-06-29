#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"linkstack.c"
#define num "1234567890"
#define type "+-*/"
#define leftbracket  "({[<"
#define rightbracket ")}]>"

int compare(char* str, char c)
{
	while(*str != '\0')
	{
		if (*str == c)
		{
			return 1;
		}
	}
	return -1;
}

int judge(char* c)
{
	int ret = 0, i = 0;

	char* strlist[] = {num, type, leftbracket, rightbracket};

	for (i = 0; i < sizeof(strlist); i++)
	{
		if (compare(strlist[i], *c))
		{
			switch (i)
			{
				case '0':
					return 1;
				case '1':
					return 2;
				case '2':
					return 3;
				case '3':
					return 4;
				default:
					break;
			}
		}
	}
	return 0;
}

int match(char* from, char* to)
{
	if (compare(leftbracket, *from) && compare(rightbracket, *to))
	{
		switch (*from)
		{
			case '(':
				if (*to == ')')
					return 1;
			case '{':
				if (*to == '}')
					return 1;
			case '[':
				if (*to == ']')
					return 1;
			case '<':
				if (*to == '>')
					return 1;
		}
	}

	return -1;
}

int transform(const char* str)
{
	int len = strlen(str);
	char* filter = (char*)malloc(sizeof(char) * len);
	char* string = filter;
	char ch = '\0';
	
	while(*str != '\0')
	{
		if (isspace(*str))
		{
			str++;
		}
		else
		{
			*string = *str;
			string++;
			str++;
		}
	}
	
	*string = '\0';
	printf("%s\n", filter);
	LinkStack* linkstack = LinkStack_Create();

	while(*filter != '\0')
	{
		printf("%d\n", judge(filter));
		switch (judge(filter))
		{
			case 1:
				printf("%c", *filter);
			case 2:
				ch = *((char*)LinkStack_Top(linkstack));
				if (compare(leftbracket, ch))
				{
					LinkStack_Push(linkstack, filter); // 入栈	
				}
				else
				{
					ch = *((char*)LinkStack_Pop(linkstack));
					printf("%c", ch);
					LinkStack_Push(linkstack, filter); // 入栈
				}
			case 3:
				{
					char *result = NULL;
					ch = *((char*)LinkStack_Pop(linkstack));
					while (match(filter, &ch) == -1)
					{
						printf("%c", ch);
						ch = *((char*)LinkStack_Pop(linkstack));
					}
					printf("%c", ch);
				}
		}
		filter++;
	}

	int size = LinkStack_Size(linkstack);
	int i = 1;
	for (i = 1; i < size; i++)
	{
		printf("%c", *((char*)LinkStack_Pop(linkstack)));
	}

	return 0;
}

void result(int ret)
{
	if (ret == 0)
	{
		printf("transform successfully\n");
	}
	else
	{
		printf("transform failed\n");
	}
}

int main()
{
	int ret = 0;
	const char* expr = "8 + ( 3 - 1 ) * 5 ";
	ret = transform(expr);
	result(ret);
}
