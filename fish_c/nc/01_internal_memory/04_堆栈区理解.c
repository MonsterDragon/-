#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 堆
char *getNUM(int num)
{
	char *p1 = NULL;
	p1 = (char*)malloc(sizeof(char) * num);
	if (p1 == NULL)
	{
		return NULL;
	}
	return p1;
}

// 栈
char * getNum2()
{
	char buf[64];
	strcpy(buf, "123456789");
	printf("buf : %s\n", buf);
	return buf;
}

void main()
{
	char * tmp = NULL;
	tmp = getNUM(10);
	if (tmp == NULL)
	{
		return;
	}
	strcpy(tmp, "111222"); // 将111222拷贝到tmp所指向的内存空间
	printf("tmp: %s\n", tmp);
	tmp = getNum2();
	printf("tmp: %s\n", tmp);
}
