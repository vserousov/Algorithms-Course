#include "InsertionSort.h"

void InsertionSort::sort(int a[], int n)
{
    for (int i = 1; i < n; i++) {

        // Element to insert
        int b = a[i];

        // Iteration variable
        int j = i - 1;
        
        // Shift
        while (b < a[j] && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }

        // Insertion
        a[j + 1] = b;
    }
}

string InsertionSort::name()
{
    return "Insertion sort";
}