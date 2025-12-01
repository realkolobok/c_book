#include <stdio.h>

/* original function
 * delete all c from s
 * void squeeze(char s[], int c)
 * {
 *  int i, j;
 *  for (i = j = 0; s[i] != '\0'; i++)
 *      if (s[i] != c)
 *          s[j++] = s[i];
 *  s[j] = '\0';
 * }
 */

int cins(char s[], int c);
void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "m3esusage";
    char s2[] = "wu3";
    printf("s1 (with junk): %s\n", s1);
    printf("s2: %s\n", s2);
    squeeze(s1, s2);
    printf("After squeeze (s1): %s\n", s1);
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

/* Delete all character in s1 that matches any character in s2 */
void squeeze(char s1[], char s2[])
{
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++)
        if (!cins(s2, s1[i]))
            s1[j++] = s1[i];
    s1[j] = '\0';
}
