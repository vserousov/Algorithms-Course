#include "sortings.h";

// Function prototypes
void buildHeap(int a[], int n);
void heapify(int a[], int n, int i);
void swap(int a[], int i, int j);
int right(int i);
int left(int i);

// Heap sort function
void heap_sort(int a[], int n) {
    //TODO: write your heap sort
    buildHeap(a, n);
    int length = n - 1;
    while (length > 0) {
        swap(a, 0, length);
        heapify(a, length, 0);
        length--;
    }
}

// Build the heap in array
void buildHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

// Put elements of array in heap order
void heapify(int a[], int n, int i) {
    // Left child
    int l = left(i);

    // Right child
    int r = right(i);

    // Largest
    int largest = i;

    // Case when largest is left child
    if (l < n && a[i] < a[l]) {
        largest = l;
    }

    // Case when largest is right child
    if (r < n && a[largest] < a[r]) {
        largest = r;
    }

    // If largest is not current element
    if (i != largest) {
        swap(a, i, largest);
        heapify(a, n, largest);
    }
}

// Swap 2 elements in array: a[i] and a[j]
void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Get index of right child
int right(int i) {
    // Because we start from 0
    return 2 * i + 2;
}

// Get index of left child
int left(int i) {
    // Because we start from 0
    return 2 * i + 1;
}

// Array generation function
void array_generation(int result[], int n, int min, int max) { 
    //TODO: you need to provide your array generation
    for (int i = 0; i < n; i++) {
        result[i] = min + rand() % (max - min + 1);
    }
}

// Array output function
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

// Sorting check function
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