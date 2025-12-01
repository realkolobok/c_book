// only check for unmatched parentheses, quotes and brackets

#include <stdio.h>

int main()
{
    int c, parentheses, sq_br, curl_br, quotes;
    int error = 0;
    while ((c = getchar()) != EOF) {
        if (c == '(' || c == ')') {
            ++parentheses;
        } else if (c == '{' || c == '}') {
            ++curl_br;
        } else if (c == '[' || c == ']') {
            ++sq_br;
        } else if (c == '"') {
            ++quotes;
        }
    }
    if (parentheses != 0 && parentheses % 2 != 0) {
        printf("Missing parentheses\n");
        error = 1;
    }
    if (sq_br != 0 && sq_br % 2 != 0) {
        printf("Missing sq_br\n");
        error = 1;
    }
    if (curl_br != 0 && curl_br % 2 != 0) {
        printf("Missing curl_br\n");
        error = 1;
    }
    if (quotes != 0 && quotes % 2 != 0) {
        printf("Missing quotes\n");
        error = 1;
    }
    if (error == 1)
        return 1;
    return 0;
}


