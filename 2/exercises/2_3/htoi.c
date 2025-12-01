/* Convert hex string to int */

#include <stdio.h>

char to_lower(char c);
int htoi(char s[]);

int main()
{
    char hex[] = "0x4A"; // 74
    printf("%s -> %d\n", hex, htoi(hex));
    return 0;
}

int htoi(char s[])
{
    int i, result;
    result = 0;
    char c;
    if (s[0] != '0' && to_lower(s[1]) != 'x')
        return -1;
    for (i = 0; s[i] != '\0'; ++i) {
        c = to_lower(s[i]);
        if (c >= '0' && c <= '9')
            result = result * 16 + (c - '0');
        else if (c >= 'a' && c <= 'f')
            result = result * 16 + 10 + (c - 'a');
        // 0x4a => 4 * 16 + 10 * 1 = 74 (correct way)
        // 0x4a => (0 * 16 + 4) * 16 + 10 + 0 = 74 (my way)
    }
    return result;
}

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c = c + 'a' - 'A';
    return c;
}
