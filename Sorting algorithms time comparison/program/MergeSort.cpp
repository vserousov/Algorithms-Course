#include "MergeSort.h"

void MergeSort::sort(int a[], int n)
{
    divide_and_merge(a, 0, n - 1);
}

void MergeSort::divide_and_merge(int *a, int l, int r)
{
    // if left less than rigt
    if (l < r)
    {
        // middle
        int m = (l + r) / 2;
        // sort left subarray
        divide_and_merge(a, l, m);
        // sort right subarray
        divide_and_merge(a, m + 1, r);
        // merge arrays
        merge(a, l, r);
    }
}

void MergeSort::merge(int *a, int l, int r)
{
    // middle
    int m = (l + r) / 2;
    // create new temporary array
    int* b = new int[r + 1];

    // copy values of array
    for (int i = l; i <= r; i++)
    {
        b[i] = a[i];
    }

    int p1 = l;
    int p2 = m + 1;

    // merge
    for (int k = l; k <= r; k++)
    {
        if (p1 > m || p2 > r) 
        {
            if (p1 > m) 
            {
                a[k] = b[p2];
                p2++;
            }
            else
            {
                a[k] = b[p1];
                p1++;
            }
        } 
        else
        {
            if (b[p1] > b[p2])
            {
                a[k] = b[p2];
                p2++;
            }
            else
            {
                a[k] = b[p1];
                p1++;
            }
        }
    }

    // clean memory
    delete[] b;
}

string MergeSort::name()
{
    return "Merge sort";
}