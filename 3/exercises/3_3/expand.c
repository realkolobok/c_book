/* Write a function expand(s1,s2) that expands shorthand notations like a-z in
 * the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
 * and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a
 * leading or trailing - is taken literally.
 * */

#include <ctype.h>
#include <stdio.h>

#define MAXSIZE 100

void expand(char s1[], char s2[]);

int main()
{
    int c, i;
    i = 0;
    char s1[MAXSIZE], s2[MAXSIZE];
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            expand(s1, s2);
            i = 0;
            printf("Original: %s\n", s1);
            printf("Expanded: %s\n", s2);
        } else {
            s1[i] = c;
            i++;
        }
    }
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j;
    int start, dash, end;
    for (i = j = 0; s1[i] != '\0'; i++) {
            start = s1[i];
            dash = s1[i+1];
            end = dash != '\0' ? s1[i+2] : '\0';
            if (dash == '-' && end > start && ((isdigit(start) && isdigit(end)) ||
                                            (isupper(start) && isupper(end)) ||
                                            (islower(start) && islower(end)) )) {
                while (end != start)
                    s2[j++] = start++;
                i++;
            } else {
                s2[j++] = s1[i];
            }
    }
    s2[j] = '\0';
}
