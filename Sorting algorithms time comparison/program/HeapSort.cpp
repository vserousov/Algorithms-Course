#include "HeapSort.h"

void HeapSort::sort(int a[], int n)
{
	buildHeap(a, n);
	int length = n - 1;
	while (length > 0)
	{
		int temp = a[0];
		a[0] = a[length];
		a[length] = temp;
		//swap(a, 0, length);
		heapify(a, length, 0);
		length--;
	}
}

void HeapSort::buildHeap(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
}

void HeapSort::heapify(int a[], int n, int i)
{
	// Left child
	int l = left(i);

	// Right child
	int r = right(i);

	// Largest
	int largest = i;

	// Case when largest is left child
	if (l < n && a[i] < a[l])
	{
		largest = l;
	}

	// Case when largest is right child
	if (r < n && a[largest] < a[r])
	{
		largest = r;
	}

	// If largest is not current element
	if (i != largest)
	{
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		heapify(a, n, largest);
	}
}

int HeapSort::left(int i)
{
	// Because we start from 0
	return 2 * i + 1;
}

int HeapSort::right(int i)
{
	// Because we start from 0
	return 2 * i + 2;
}

string HeapSort::name()
{
	return "Heap sort";
}