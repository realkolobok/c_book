#include <stdio.h>

#define TAB_LENGTH 8

int main()
{
    int c, spaces;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            spaces = TAB_LENGTH;
            while (spaces) {
                putchar(' ');
                --spaces;
            }
        } else {
            putchar(c);
        }
    }
    return 0;
}
