#include <stdio.h>

int lower(int c);
void to_lower(char s[]);

int main()
{
    char msg[] = "HELLO";
    printf("%s\n", msg);
    to_lower(msg);
    printf("%s\n", msg);
    return 0;
}

int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

void to_lower(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; ++i)
        s[i] = lower(s[i]);
}
