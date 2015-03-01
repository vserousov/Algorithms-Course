#include "BubbleIverson2.h"

void BubbleIverson2::sort(int a[], int n)
{
    int bound = n - 1;
    int i = 0, t = 0;
    
    while (true)
    {
        t = 0;
        while (i < bound)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                t = i;
            }
            i++;
        }

        if (t != 0) {
            bound = t;
            i = 0;
        } else {
            break;
        }
    }
}

string BubbleIverson2::name()
{
    return "Iverson 2";
}