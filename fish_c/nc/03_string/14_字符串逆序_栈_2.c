#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

char g_str[1024];

// 通过递归的方式，逆向打印
// 递归和全局变量（把逆序的结果）
// 递归和非全局变量（递归指针做函数参数）
void reversal(char *p)
{
	if (p == NULL)
	{
		return;
	}
	if (*p == '\0')
	{
		return;
	}
	// 不能使用p++或++p
	reversal(p+1); // 注意此时没有执行打印，而是执行了函数调用，让字符串的每一个地址入栈
	printf("*p: %c\n", *p);
}

void reversal_2(char *p)
{
	if (p == NULL)
	{
		return;
	}
	if (*p == '\0')
	{
		return;
	}
	reversal_2(p+1);
	// strcat(g_str, p); // 会将p所对应的全部字符串都拷贝到g_str
	strncat(g_str, p, 1); // 会将p所对应的一个字符拷贝到g_str字符串的末尾并添加'\0'
}

void reversal_3(char *p, char *tmp)
{
	if (p == NULL || tmp == NULL)
	{
		return;
	}
	if (*p == '\0')
	{
		return;
	}
	reversal_3(p+1, tmp);
	strncat(tmp, p, 1);
	// strncpy(tmp, p, 1); 始终将p所指向的一个字符拷贝到tmp首字符
}

int main()
{
	char p[] = "aaabbbcccddd";
	reversal(p);

	memset(g_str, 0, sizeof(g_str));
	reversal_2(p);
	printf("g_str: %s\n", g_str);

	char tmp[1024];
	reversal_3(p, tmp);
	printf("tmp: %s\n", tmp);
}
