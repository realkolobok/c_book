#include <stdio.h>

#define TABSIZE 8

void getline(char line[], int size);
void detab(char line[]);
void copy(char from[], char to[]);

int main()
{
	return 0;
}

int getline(char line[], int size)
{
    int c, i;
    for (i = 0; i < size-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;
}

void detab(char line[])
{
	int col, spaces, n;
	n = TABSIZE;
}

void copy(char from[], char to[])
{
    int i;
    for (i = 0; from[i] != '\0'; ++i)
        to[i] = from[i];
    to[i] = '\0';
}
