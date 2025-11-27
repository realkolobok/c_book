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
        printf("%s", clean_line);
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
    int i, j, state;
    state = OUT;
    j = i = 0;
    while (line[i] != EOF) {
        if (line[i] == '\t' || (line[i] == ' ' && state == IN)) {
            state = OUT;
        } else if (state == OUT && line[i] != ' ') {
            state = IN;
            ++j;
        }
        ++i;
        line[i] = line[j]; // SOMETHING DOESNT WORK HERE !!!!!
    }
}
