#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define Maxline 2048

int main()
{
	char *filename = "cfg.ini";
	FILE *fp = NULL;
	char line[Maxline] = {0};

	fp = fopen(filename, "r");
	fgets(line, Maxline, fp);
	printf("%s\n", line);
}
