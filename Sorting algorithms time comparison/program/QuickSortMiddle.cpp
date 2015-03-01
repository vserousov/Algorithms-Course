#include "QuickSortMiddle.h"

void QuickSortMiddle::sort(int a[], int n)
{
	call(a, 0, n - 1);
}

void QuickSortMiddle::call(int a[], int left, int right)
{
	int i = left;
	int j = right;
	int temp;
	int pivot = a[(left + right) / 2];
	while (i <= j) {

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
 
	if (left < j) {
		call(a, left, j);
	}

	if (i < right) {
		call(a, i, right);
	}
}

string QuickSortMiddle::name()
{
	return "Quick sort (middle)";
}