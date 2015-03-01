#include "sortings.h";

void insertion_sort(int a[], int n) {
    //TODO: write your insertion sort
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

void binary_sort(int a[], int n) {
    //TODO: write your binary insertion sort
    for (int i = 1; i < n; i++) {

        // Left
        int lf = 0;

        // Right
        int rg = i;

        // Binary search for interval
        while (lf < rg) { 
            int c = (lf + rg) / 2;
            if (a[i] >= a[c]) {
                lf = c + 1;
            } else {
                rg = c;
            }
        }

        // Element to insert
        int p = a[i];

        // Shift
        for (int k = i; k > lf; k--) {
            a[k] = a[k - 1];
        }

        // Insertion
        a[lf] = p;
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

// Function for array copy
void copy_array(int arr1[], int arr2[], int n) {
    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i];
    }
}

// Function for sorting array (2 argument is method of sorting)
void sort_array(string sort_name, void (*arr_sort)(int[], int), int arr[], int size, int testNumber) {
    cout << sort_name << endl;
    cout << "Test number: " << testNumber << endl;
    cout << "Original array" << endl;
    results(arr, size);
    arr_sort(arr, size);
    cout << "Sorted array" << endl;
    results(arr, size);

    if (is_sort(arr, size)) {
        cout << "Array was sorted correctly" << endl;
    } else {
        cout << "Array wasn't sorted correctly" << endl;
    }
    cout << endl;
}

// Recursive function for parsing ints with optional range and with printing message
int try_parse(string message, int min, bool minb, int max, bool maxb) {
    // Print message
    cout << message;
    
    // Read number from keyboard
    int result;
    cin >> result;
    
    // Detect if it wasn't a number
    bool fail = cin.fail();
    // Clear stream
    cin.clear();
    cin.ignore(10000, '\n');

    // If it failed or it is out of range it starts from the beginning (recursively)
    if (fail || (minb && result < min) || (maxb && result > max)) {
        return try_parse(message, min, minb, max, maxb);
    } else {
        return result;
    }
}