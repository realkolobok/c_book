#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_SIZE 1000

int get_line(char line[], int size);
void trim(char line[]);

int main()
{
    char clean_line[MAX_SIZE];
    while (get_line(clean_line, MAX_SIZE) > 0) {
	trim(clean_line);
	if (clean_line[0] != '\0')
        	printf("%s\n", clean_line);
    }
    return 0;
}

int get_line(char line[], int size)
{
    int c, i;
    for (i = 0; i < size-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void trim(char line[])
{
	int i = 0;
	while (line[i] != '\0')
		++i;

	while (i > 0 && (line[i-1] == ' ' || line[i-1] == '\t' || line[i-1] == '\n'))
		--i;
	line[i] = '\0';
}
