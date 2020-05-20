#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int render(char *str, char ***array, int *length)
{
	char *p = str; // 字符串的头指针

	if (str == NULL || array == NULL)
	{
		return -1;
	}

	char *final = str + strlen(str) * sizeof(char); // 字符串为指针
	char *find = NULL;
	char *create = NULL;
	int l; // 字符串长度
	int count = 0; // 统计字符串个数

	while (strchr(p, ',') != NULL)
	{
		p = strchr(p, ',') + 1;
		count++;
	}
	count++;
	*length = count;

	char **seq = (char **)malloc(sizeof(char *) * count);
	int i = 0;
	p = str;
	// while (strchr(p, ',') != NULL)
	// {
	// 	// 静态语言不能修改定义的变量的大小
	// 	find = strchr(p, ',');
	// 	l = find - p;
	// 	seq[i] = (char *)malloc(sizeof(char) * l);
	// 	printf("%p\n", seq[i]);
	// 	int j;
	// 	for (j = 0; j < l; j++)
	// 	{
	// 		seq[i][j] = p[j];
	// 	}
	// 	p = strchr(p, ',') + 1;
	// 	printf("%p\n", p);
	// 	printf("%s\n", p);
	// 	i++;
	// }
	for (i; i<count; i++)
	{
		if (strchr(p, ',') != NULL)
		{
			find = strchr(p, ',');
			l = find - p;
			seq[i] = (char *)malloc(sizeof(char) * l);
			if (seq[i] == NULL)
			{
				goto END;
			}
			int j;
			// for (j=0; j<l; j++)
			// {
			// 	seq[i][j] = p[j];
			// }
			strncat(seq[i], p, l);
			p = strchr(p, ',') + 1;
		}
		else
		{
			l = final - p;
			seq[i] = (char *)malloc(sizeof(char) * l);
			if (seq[i] == NULL)
			{
				goto END;
			}
                        int j;
                        for (j=0; j<l; j++)
                        {
                                seq[i][j] = p[j];
                        }
		}
	}
	*array = seq;
	return 1;

END:
	i = 0;
	if (seq == NULL)
	{
		return -1;
	}
	for (i=0; i<count; i++)
	{
		if (seq[i] != NULL)
		{
			free(seq[i]);
			seq[i] = NULL;
		}
	}
	if (seq != NULL)
	{
		free(seq);
		seq = NULL;
	}
}

int main()
{
	char *myStr = "(\"abcdef,acccd,eeee,aaaa,e3eeeee,ssssss,\";)";
	char **myArray = NULL;
	int result;
	int num;

	result = render(myStr, &myArray, &num);
	if (result == 1)
	{
		int i;
		for (i=0; i<num; i++)
		{
			printf("myArray[%d]: %s\n", i, myArray[i]);
		}
	}
}
