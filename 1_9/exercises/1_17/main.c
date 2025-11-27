#include <stdio.h>

#define MAX_LENGTH 1000

int get_line(char s[], int lim);
void copy(char from[], char to[]);

int main()
{
    int len, max;
    char line[MAX_LENGTH];
    char longest[MAX_LENGTH];

    max = 0;
    while ((len = get_line(line, MAX_LENGTH)) > 0) {
        if (len >= 80)
            printf("%s", line);
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    if (c != '\n' && c != EOF) {
        while ((c = getchar()) != EOF && c != '\n')
            ++i;
        if (c == '\n')
            ++i;
    }
    return i;
}

void copy(char from[], char to[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
    return;
}
