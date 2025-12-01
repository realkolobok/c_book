#include <stdio.h>

void do_something(int s[], int n);

int main()
{
    int size = 40;
    int nums[size];
    for (int i = 0; i < size-1; i++)
        nums[i] = i;
    do_something(nums, 20);
    return 0;
}

void do_something(int s[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%6d%c", s[i], (i%10==9 || i==n-1) ? '\n' : ' ');
}
