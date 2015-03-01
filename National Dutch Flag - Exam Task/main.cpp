#include <iostream>
#include "KR_1.h"

/*
	Student: Serousov Vitaly
	Group: 201 SE
*/
void qsort_3(int* arr, int from, int to, int &depth)
{
	if (from > to)
	{
		return;
	}

	int pivot = arr[to];
	int i = from;
	int j = to - 1;
	int p = from;
	int q = to - 1; 

	while (i < j)
	{
		
		while (arr[i] < pivot)
		{
			++i;
		}

		while (arr[j] > pivot)
		{
			--j;
		}

		if (i < j)
		{
			swap(arr[i], arr[j]);


			if (arr[i] == pivot)
			{
				swap(arr[p++], arr[i]);
			}

			if (arr[j] == pivot)
			{
				swap(arr[q--], arr[j]);
			}

			i++;
			j--;
		}

	} 

	while (j > from && p > from)
	{
		if (arr[p - 1] > arr[j])
		{
			swap(arr[--p], arr[j--]);
		}
		else
		{
			j--;
		}
	}

	while (i < to && q < to)
	{
		if (arr[q + 1] < arr[i])
		{
			swap(arr[++q], arr[i++]);
		}
		else
		{
			++i;
		}
	}

	if (j > from)
	{

		qsort_3(arr, from, j, depth);
	}

	if (i < to)
	{
		qsort_3(arr, i, to, depth);
	}

}

/*
void results(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void main() {

	int arr[11] = {5, 4, 2, 6, 2, 1, 3, 5, 7, 6, 3};

	int depth = 0;
	qsort_3(arr, 0, 10, depth);
	cout << depth << endl;
	results(arr, 11);
	system("pause");
}*/