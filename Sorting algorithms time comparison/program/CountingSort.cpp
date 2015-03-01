#include "CountingSort.h"
#include <iostream>
using namespace std;

void CountingSort::sort(int a[], int n)
{
	// Maximum of array
	int k = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > k)
		{
			k = a[i];
		}
	}

	// Create array for counting
	int* c = new int[k + 1];

	// Create array for saving result
	int* b = new int[n];

	// Set 0 for all elements of counting array
	for (int i = 0; i <= k; i++) {
		c[i] = 0;
	}

	// c[i] is the number of elements of array a equal i
	for (int i = 0; i < n; i++) {
		c[a[i]] = c[a[i]] + 1;
	}

	// Find partly summ
	for (int j = 1; j <= k; j++) {
		c[j] = c[j] + c[j - 1];
	}

	// b is sorted array, if array a contains copies they will put on their position
	for (int i = n - 1; i >= 0; i--) {
		b[c[a[i]] - 1] = a[i];
		c[a[i]] = c[a[i]] - 1;
	}

	// Copy array for returning result
	//copy_arr(a, b, n);
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}

	// Clean memory
	delete[] b;
	delete[] c;
}

string CountingSort::name() 
{
	return "Counting sort";
}