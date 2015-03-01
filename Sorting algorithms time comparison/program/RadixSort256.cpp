#include "RadixSort256.h"

void RadixSort256::sort(int a[], int n)
{
    // Union of int (4 bytes) and char[4] (1 bytes * 4 = 4 bytes)
    union Numbers
    {
        unsigned char bytes[4];
        int value;
    };
    
    // Array of unions
    Numbers* numbers = new Numbers[n];
    
    // Initialize array of unions
    for (int i = 0; i < n; i++)
    {
        numbers[i].value = a[i];
    }

    // Array for results
    int* b = new int[n];

    // Notation
    int k = 256;
    
    // Loop for all digits
    for (int i = 0; i < 4; i++)
    {
        // Create array for counting
        int * c = new int[k];

        // Set 0 for all elements of counting array
        for (int j = 0; j < k; j++) 
        {
            c[j] = 0;
        }

        // Count elements for all digits
        for (int j = 0; j < n; j++) 
        {
            numbers[j].value = a[j];
            c[numbers[j].bytes[i]]++;
        }

        // Find partly summ
        for (int j = 0, count = 0; j < k; j++) 
        {
            int tmp = c[j];
            c[j] = count;
            count += tmp;
        }

        // b is sorted array, if array a contains copies they will put on their position
        for (int j = 0; j < n; j++) 
        {
            b[c[numbers[j].bytes[i]]] = a[j];
            c[numbers[j].bytes[i]]++;
        }

        // Copy array for returning result
        //copy_arr(a, b, n);
        for (int i = 0; i < n; i++)
        {
            a[i] = b[i];
        }

        // Clean memory
        delete[] c;
    }
    // Clean memory
    delete[] b;
    delete[] numbers;
}

string RadixSort256::name()
{
    return "Radix 256 sort";
}