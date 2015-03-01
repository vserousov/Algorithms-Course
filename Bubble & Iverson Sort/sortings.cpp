#include "sortings.h";


void bubble_sort(int a[], int n) {
    //TODO: write your bubble sort 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void bubble_iverson_1(int a[], int n) {
    //TODO: write your bubble sort with Iverson I
    bool t = false;
    for (int i = 0; i < n - 1 && !t; i++) {
        t = true;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                t = false;
            }
        }
    }
}

void bubble_iverson_2(int a[], int n) {
    //TODO: write your bubble sort with Iverson II
    int bound = n - 1;
    int i = 0, t = 0;
    
    while (t != -1) {
        t = -1;
    
        while (i < bound) {
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                t = i;
            }
            i++;
        }

        if (t != -1) {
            bound = t;
            i = 0;
        }
    }
}

void array_generation(int result[], int n, int min, int max) { 
    //TODO: you need to provide your array generation
    for (int i = 0; i < n; i++) {
        result[i] = min + rand() % (max - min + 1);
    }
}

void results(int a[], int n) {
    //TODO: you need to output array, use standart c++ output
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool is_sorted(int a[], int n) {
    //TODO: you need to check if array sorted or not
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}