#include "BubbleIverson1.h"

void BubbleIverson1::sort(int a[], int n)
{
    bool t = false;
    for (int i = 0; i < n - 1 && !t; i++)
    {
        t = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                t = false;
            }
        }
    }
}

string BubbleIverson1::name()
{
    return "Iverson 1";
}

