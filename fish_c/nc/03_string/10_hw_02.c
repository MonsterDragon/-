#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

void sort(char *orstr, char *todd, char *teven)
{
	char *from = orstr;
	char *odd = todd;
	char *even = teven;
	printf("odd: %p\n", odd);
	printf("even: %p\n", even);
	int i = 0;

	while (from[i] != '\0')
	{
		if (i%2 == 0)
		{
			printf("%d\n", i);
			*even = from[i];
			even++;
		}
		else
		{
			*odd = from[i];
			odd++;
		}
		i++;
	}
	*even = '\0';
	*odd = '\0';
}

int main()
{
	char *ostr = "1a2b3c4d5";
	printf("%d\n", strlen(ostr) / 2);
	char odd[strlen(ostr) / 2 + 1];
	char even[strlen(ostr) / 2];
	printf("odd: %p\n", odd);
	printf("even: %p\n", even);
	printf("odd: %d\n", sizeof(odd));
	printf("even: %d\n", sizeof(even));

	sort(ostr, odd, even);

	printf("odd: %s\n", odd);
	printf("even: %s\n", even);
}
