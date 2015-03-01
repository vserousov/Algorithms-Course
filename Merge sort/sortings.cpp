#include "sortings.h";

// Despite the incapsulation, decomposisition was made here to make it generally testable.
// (In real life, functions divide_and_merge() and merge() should be hidden (for example, private))

// Initial call of function.
// void merge_sort(int* arr, int n);

// Recursive function to divide the array and merge it in current bounds [from, to].
void divide_and_merge(int* arr, int l, int r);

// Method to merge two sorted pieces of array to one sorted piece.
// Normally, first piece indexes are in bounds: [from, from + (to - from) / 2];
// second piece indexes are in bounds: [from + (to - from) / 2 + 1, to];
// method should make the array sorted in bounds [from, to] in O(n) time complexity.
void merge(int* arr, int l, int r);

void merge_sort(int a[], int n) {
	//TODO: write your merge sort
	divide_and_merge(a, 0, n - 1);
}

void divide_and_merge(int* a, int l, int r) {
	// if left less than rigt
	if (l < r) {
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

void merge(int* a, int l, int r) {
	// middle
	int m = (l + r) / 2;
	// create new temporary array
	int* b = new int[r + 1];

	// copy values of array
	for (int i = l; i <= r; i++) {
		b[i] = a[i];
	}

	int p1 = l;
	int p2 = m + 1;

	// merge
	for (int k = l; k <= r; k++) {
		if (p1 > m || p2 > r) {
			if (p1 > m) {
				a[k] = b[p2];
				p2++;
			} else {
				a[k] = b[p1];
				p1++;
			}
		} else {
			if (b[p1] > b[p2]) {
				a[k] = b[p2];
				p2++;
			} else {
				a[k] = b[p1];
				p1++;
			}
		}
	}

	// clean memory
	delete[] b;
}

void array_generation(int result[], int n, int min, int max) { 
	//TODO: you need to provide your array generation
	for (int i = 0; i < n; i++) {
		result[i] = min + rand() % (max - min + 1);
	}
}

void results(int a[], int n) {
	//TODO: you need to output array, use standart c++ output
	cout << "[";
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i < n - 1) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

bool is_sort(int a[], int n) {
	//TODO: you need to check out your array is sorted or not
	//return false or true;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) {
			return false;
		}
	}
	return true;
}