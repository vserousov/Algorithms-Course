#include "ShellSort.h"

void ShellSort::sort(int a[], int n)
{
	int i;
	int j;
	int k;
	int t;
	for (k = n / 2; k > 0; k /= 2)
	{
        for (i = k; i < n; i++)
        {
            t = a[i];
            for (j = i; j >= k; j -= k)
            {
                if (t < a[j - k])
				{
                    a[j] = a[j - k];
				}
                else
				{
					break;
				}
            }
            a[j] = t;
        }
	}
}

string ShellSort::name()
{
	return "Shell Sort";
}