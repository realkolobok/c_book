/*
 * If array size is very big, then this program will crash with segmentation fault.
 * This happens because of the limited stack size. This can be examined in gdb.txt file
 *
 * gdb is actually so useful, i need to play more with it
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int binsearch_new(int x, int v[], int n);

#define ARRAYLEN 100000
#define SAMPLESIZE 1000

int main()
{
    clock_t start, end;
    int arr[ARRAYLEN]; // array to search
    int i;
    for (i = 0; i < ARRAYLEN; i++)
        arr[i] = i;
    int t[SAMPLESIZE]; // random nums to look for
    for (i = 0; i < SAMPLESIZE; i++)
        t[i] = rand() % (ARRAYLEN+1);

    start = clock();
    for (i = 0; i < SAMPLESIZE; i++)
        binsearch(t[i], arr, ARRAYLEN);
    end = clock();
    printf("binsearch:\t%6ld clock tics\n", end - start);
    start = clock();
    for (i = 0; i < SAMPLESIZE; i++)
        binsearch_new(t[i], arr, ARRAYLEN);
    end = clock();
    printf("binsearch_new:\t%6ld clock tics\n", end - start);
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
