#include "BinarySort.h"

void BinarySort::sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // Left
        int lf = 0;

        // Right
        int rg = i;

        // Binary search for interval
        while (lf < rg)
        { 
            int c = (lf + rg) / 2;
            if (a[i] >= a[c])
            {
                lf = c + 1;
            }
            else
            {
                rg = c;
            }
        }

        // Element to insert
        int p = a[i];

        // Shift
        for (int k = i; k > lf; k--)
        {
            a[k] = a[k - 1];
        }

        // Insertion
        a[lf] = p;
    }
}

string BinarySort::name()
{
    return "Binary sort";
}