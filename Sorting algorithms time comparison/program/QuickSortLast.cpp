#include "QuickSortLast.h"

void QuickSortLast::sort(int a[], int n)
{
	call(a, 0, n - 1);
}

void QuickSortLast::call(int a[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = a[j];
	int temp;

	while (i <= j)
	{
		while (a[i] < pivot)
		{
			++i;
		}

		while (a[j] > pivot)
		{
			--j;
		}

		if (i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			++i;
			--j;
		}
	}
 
	if (left < j)
	{
		QuickSortLast::call(a, left, j);
	}

	if (i < right)
	{
		QuickSortLast::call(a, i, right);
	}
}

string QuickSortLast::name()
{
	return "Quick sort (last)";
}