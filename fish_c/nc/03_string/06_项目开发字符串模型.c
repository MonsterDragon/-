#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	// strstr()函数用来检索子串在字符串中首次出现的位置
	// char *strstr( char *str, char * substr );
	// str为要检索的字符串，substr为要检索的子串。返回字符串str中第一次出现子串substr的地址；如果没有检索到子串，则返回NULL
	
	char *p = "aaabbb123cccasckas123sjlac123";
	int count = 0;
	
	do
	{
		p = strstr(p, "123");
		if (p == NULL)
			break;
		else
		{
			count++;
			p = p + strlen("123");
		}
	} while(*p != '\0');

	printf("count: %d\n", count);

	char *p2 = "aaabbb123cccasckas123sjlac123";
	int count_2 = 0;

	while(*p2 != '\0')
	{
		p2 = strstr(p2, "123");
		if (p2 == NULL)
			break;
		else
		{
			count_2++;
			p2 += strlen("123");
		}
	}

	printf("count_2: %d\n", count_2);

	char *p3 = "aaabbb123cccasckas123sjlac123";
	int count_3 = 0;

	while (p3 = strstr(p3, "123")) // 其中用来判断循环条件的expr可以是任意表达式。当其是赋值语句的时候，含义为，先执行赋值语句，然后对左值进行判断。如果左值为0则expr为假，while退出；否则expr为真，while继续循环。
	{
		count_3++;
		p3 += strlen("123");
	}

	printf("count_3: %d\n", count_3);
}
