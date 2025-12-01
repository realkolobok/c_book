#include <stdio.h>

int cins(char s[], int c);
int any(char s1[], char s2[]);

int main()
{
    char s1_1[] = "abcccdce";
    char s2_1[] = "klopc";

    char s1_2[] = "12345";
    char s2_2[] = "qewruiop";

    /* Expected: 2 */
    int res = any(s1_1, s2_1);
    printf("Result: %d\n", res);
    if (res > -1)
        printf("At resulted position: %c\n", s1_1[res]);

    /* Expected: -1 */
    res = any(s1_2, s2_2);
    printf("%d\n", res);
    if (res == -1)
        printf("Not found\n");
    return 0;
}

/* Return 1 if if string s contains character c, 0 otherwise */
int cins(char s[], int c)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return 1;
    return 0;
}

/* Return first location in s1 where any s2 character occurs
 * or -1 if s1 contains no characters from s2 */
int any(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] != '\0'; i++)
        if (cins(s2, s1[i]))
            return i;
    return -1;
}
