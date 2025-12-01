#include <stdio.h>

enum Nums {
    ZERO,
    ONE,
    TWO
};

int main()
{
    printf("%d\n", '\0');
    enum Nums my_num = ZERO;
    printf("%d\n", my_num == 0);

    enum Nums num1 = ONE;
    printf("%d\n", num1 > my_num);

    return 0;
}
