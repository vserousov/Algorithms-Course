#include "sortings.h";

void array_copy(int a[], int b[], int n);
int array_max(int a[], int n);
int digit(int n, int p);
int num_length(int n);

void counting_sort(int a[], int n) {
    //TODO: write your stable counting sort here (only positive numbers)
    // Maximum of array
    int k = array_max(a, n);

    // Throw exception if array contains element more than 65535
    if (k > 65535) {
        throw exception("This array can't be sorted using counting sort");
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
    array_copy(a, b, n);
    
    // Clean memory
    delete[] b;
    delete[] c;
}

void radix_sort10(int a[], int n) {
    //TODO: write your radix sort here (10 number system, only positive numbers)

    // Maximum of array
    int max = array_max(a, n);

    // Count digits of max
    int m = num_length(max);

    // Notation
    int k = 10;

    // Array for results
    int* b = new int[n];

    // Loop for all digits
    for (int i = 0; i < m; i++) {

        // Create array for counting
        int* c = new int[k];
        
        // Set 0 for all elements of counting array
        for (int j = 0; j < k; j++) {
            c[j] = 0;
        }

        // Count elements for all digits
        for (int j = 0; j < n; j++) {
            int d = digit(a[j], i);
            c[d]++;
        }

        // Find partly summ
        for (int j = 0, count = 0; j < k; j++) {
            int tmp = c[j];
            c[j] = count;
            count += tmp;
        }

        // b is sorted array, if array a contains copies they will put on their position
        for (int j = 0; j < n; j++) {
            int d = digit(a[j], i);
            b[c[d]] = a[j];
            c[d]++;
        }
        
        // Copy array for returning result
        array_copy(a, b, n);

        // Clean memory
        delete[] c;
    }
    // Clean memory
    delete[] b;
}


void radix_sort256(int a[], int n) {
    //TODO: write your radix sort here (256 number system, only positive numbers)
    
    // Union of int (4 bytes) and char[4] (1 bytes * 4 = 4 bytes)
    union Numbers {
        unsigned char bytes[4];
        int value;
    };
    
    // Array of unions
    Numbers* numbers = new Numbers[n];
    
    // Initialize array of unions
    for (int i = 0; i < n; i++) {
        numbers[i].value = a[i];
    }

    // Array for results
    int* b = new int[n];

    // Notation
    int k = 256;
    
    // Loop for all digits
    for (int i = 0; i < 4; i++) {

        // Create array for counting
        int * c = new int[k];

        // Set 0 for all elements of counting array
        for (int j = 0; j < k; j++) {
            c[j] = 0;
        }

        // Count elements for all digits
        for (int j = 0; j < n; j++) {
            numbers[j].value = a[j];
            c[numbers[j].bytes[i]]++;
        }

        // Find partly summ
        for (int j = 0, count = 0; j < k; j++) {
            int tmp = c[j];
            c[j] = count;
            count += tmp;
        }

        // b is sorted array, if array a contains copies they will put on their position
        for (int j = 0; j < n; j++) {
            b[c[numbers[j].bytes[i]]] = a[j];
            c[numbers[j].bytes[i]]++;
        }

        // Copy array for returning result
        array_copy(a, b, n);

        // Clean memory
        delete[] c;
    }
    // Clean memory
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

// Copy array from b to a
void array_copy(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

// Find maximum value in array
int array_max(int a[], int n) {
    int k = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > k) {
            k = a[i];
        }
    }
    return k;
}

// Find digit on p position of number n
int digit(int n, int p) {
    int s = 1;
    for (int i = 0; i < p; i++) {
        s *= 10;
    }
    return (n / s) % 10;
}

// Get number length
int num_length(int n) {
    int length = 0;
    while (n > 0) {
        length++;
        n /= 10;
    }
    return length;
}