#include <stdio.h>

#define ARRAYLEN 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    int c, i;
    i = 0;
    char t[ARRAYLEN], s[ARRAYLEN];
    while ((c = getchar()) != EOF) {
        t[i] = c;
        i++;
    }
    escape(s, t);
    printf("%s\n", s);
    return 0;
}

void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++, j++) {
        switch (t[i]) {
            case '\t':
                s[j] = '\\';
                s[++j] = 't';
                break;
            case '\n':
                s[j] = '\\';
                s[++j] = 'n';
                break;
            case '\b':
                s[j] = '\\';
                s[++j] = 'b';
                break;
            case '\r':
                s[j] = '\\';
                s[++j] = 'r';
                break;
            case '\v':
                s[j] = '\\';
                s[++j] = 'v';
                break;
            default:
                s[j] = t[i];
                break;
        }
    }
    s[j] = '\0';
}
