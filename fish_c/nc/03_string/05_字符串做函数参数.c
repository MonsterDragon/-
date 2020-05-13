#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main_copy_str()
{
	char a[] = "I am a teacher";
	char buf[64];

	// 将a中的字符串数组拷贝到buf中
	// 不能修改buf指针常量
	
	char *p = a;
	int i = 0;
	while (*p != '\0')
	{
		*(buf + i) = *p;
		i++;
		p++;
	}
	*(buf + i) = '\0';
	printf("buf: %s\n", buf);
}

// 字符串copy函数技术推演

void copy(char *from, char *to)
{
	// int i = 0;
	// for (i = 0; *(from + i) != '\0'; i++)
	// {
	// 	*(to + i) = *(from + i);
	// }
	// *(to + i) = '\0';
	for (; *from != '\0'; from++, to++)
	{
		*to = *from;
	}
	*to = '\0';
}

// ++操作的优先级高于*
void copy2(char *from, char *to)
{
	for (; *from != '\0';)
	{
		*to++ = *from++;
	}
	*to = '\0';
}

void copy3(char *from, char *to)
{
	while ((*to = *from) != '\0')
	{
		to++;
		from++;
	}
}

void copy4(char *from, char *to)
{
	while ((*to++ = *from++) != '\0')
	{
		;
	}
}

void copy5(char *from, char *to)
{
	int a = 0;
	int b = 3;
	while ((*to++ = *from++)) // 当*from = '\0'时仍然执行赋值，但是表达式是0会退出
	{
		; // 执行空语句
	}
}

// 不轻易改变形参的
void copy6(char *from, char *to)
{
	// 用一个其他指针变量来接收形参，可以保证形参的值不变
	char *tmpfrom = from;
	char *tmpto = to;

	if (tmpfrom == NULL || tmpto == NULL)
		return;

	while((*tmpto++ = *tmpfrom++))
	;
}

int main()
{
	char *from = "abcdef";
	char buf[128];

	copy6(from, buf);

	printf("buf: %s\n", buf);
}
