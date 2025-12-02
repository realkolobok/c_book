#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch_new(int x, int v[], int n);

int main()
{
    int arr[20];
    for (int i = 0; i < 20; i++)
        arr[i] = i;
    int pos = binsearch(4, arr, 20);
    printf("binsearch:\tPos: %d\tNum at pos: %d\n", pos, arr[pos]);
    pos = binsearch_new(4, arr, 20);
    printf("binsearch_new:\tPos: %d\tNum at pos: %d\n", pos, arr[pos]);
    return 0;
}

/* binsearch: Search for x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, mid, high;
    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch_new(int x, int v[], int n)
{
    int low, mid, high;
    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (v[low] == x)
        return low;
    else if (v[high] == x)
        return high;
    else if (v[mid] == x)
        return mid;

    return -1;
}
