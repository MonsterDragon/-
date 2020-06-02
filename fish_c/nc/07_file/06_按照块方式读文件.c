#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct Teacher
{
	char name[64];
	int age;
};

int main()
{
	FILE *fp = NULL;
	struct Teacher list[6];
	char *filename = "test_02.txt";

	fp = fopen(filename, "rb");

	int i = 0;
	while (!feof(fp))
	{
		if (i < 6)
		{
			fread(&list[i], sizeof(struct Teacher), 1, fp); // int fread( void *buffer, size_t size, size_t num, FILE *stream );
			printf("%s\n", list[i].name);
		}
		else
		{
			goto END;
		}
		i++;
	}
	fclose(fp);
END:
	fclose(fp);
}
