#include <stdio.h>

#define LIMIT 100

void do_something(char s[], int lim);

int main()
{
    return 0;
}

void do_something(char s[], int lim)
{
    int c, i;
    i = 0;
    while (i < lim-1) {
        if ((c = getchar()) != '\n') {
            if (c != EOF) {
                ++i;
                s[i] = c;
            }
        }
    }
}
