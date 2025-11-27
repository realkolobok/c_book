#include <stdio.h>

int main()
{
    int c;
    long nc, nl, nt, ns;
    for (nc = 0; (c = getchar()) != EOF; ++nc) {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++nt;
        if (c == ' ')
            ++ns;
    }
    printf("NC\tNL\tNT\tNS\n");
    printf("%ld\t%ld\t%ld\t%ld\n", nc, nl, nt, ns);
}
