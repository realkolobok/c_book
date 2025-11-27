#include <stdio.h>

int main()
{
    int c, last_was_blank;
    last_was_blank = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (last_was_blank == 0)
                putchar(c);
            ++last_was_blank;
        } else {
            putchar(c);
            last_was_blank = 0;
        }
    }
}
