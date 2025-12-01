#include <stdio.h>

int main()
{
    int x, y, z;
    x = 1;
    y = 2;
    y = (x > y) ? x : y;
    printf("%d\n", y);
    return 0;
}
