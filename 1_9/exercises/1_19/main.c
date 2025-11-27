#include <stdio.h>

#define MAX_SIZE 1000

int get_line(char s[], int size);
void reverse(char s[]);
void copy(char from[], char to[]);

int main()
{
    char line[MAX_SIZE];
    while (get_line(line, MAX_SIZE) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

int get_line(char s[], int size)
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

void reverse(char s[])
{
    int len, i, j;
    for (len = 0; s[len] != '\0'; ++len)
        ;
    char temp[len+1];
    for (j = 0, i = 0; i < len; ++j, ++i) {
        if (s[len - i - 1] == '\n')
            --j;
        else {
            temp[j] = s[len - i - 1];
        }
    }
    temp[j] = '\n';
    temp[j+1] = '\0';
    copy(temp, s);
}

void copy(char from[], char to[])
{
    int i;
    for (i = 0; from[i] != '\0'; ++i)
        to[i] = from[i];
    to[i] = '\0';
}
