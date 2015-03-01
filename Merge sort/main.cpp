#include "sortings.h";
#include <string>
#include <fstream>

/*
Name + Surname: Serousov Vitaly
Group: 201(1)SE
Date: 18.10.2014
Task: Merge sort
IDE: Microsoft Visual Studio 2010
*/

// Functions prototypes
int try_parse(string message, int min = 0, bool minb = false, int max = 0, bool maxb = false);
void array_sort(string sort_name, void (*arr_sort)(int[], int), int arr[], int size, int testNumber, ofstream& fw);
void array_copy(int a[], int b[], int n);
void sortings_start(int arr1[], int size, ofstream& fw, int testNumber);
void results_out(int a[], int n, ofstream& fw);
void show_interface();
void from_file(int arr1[], ofstream& fw);
void from_keyboard(int arr1[], ofstream& fw);

// Input filename
const string input_file = "test_proekt_5.txt";
// Output filename
const string output_file = "output_proekt_5.txt";

void main() {                                  
    //TODO: make console application, use methods in sortings file

    // Unique random
    srand(time(0));

    // Exit flag
    bool exit = false;

    // Array for sorting
    static int* arr1;

    // FileStream for writing
    ofstream fw;

    // Work until exit
    while (!exit) {

        // Interface
        show_interface();
    
        // Selected item from menu
        int item = try_parse("Enter item number: ", 1, true, 3, true);
        
        // Get data from keyboard
        if (item == 1) {
            from_keyboard(arr1, fw);

        // Get data from file
        } else if (item == 2) {
            from_file(arr1, fw);

        // Exit
        } else {
            exit = true;
        }
    }
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

// Write results in file
void results_out(int a[], int n, ofstream& fw) {
    fw << "[";
    for (int i = 0; i < n; i++) {
        fw << a[i];
        if (i < n - 1) {
            fw << ", ";
        }
    }
    fw << "]" << endl;
}

// Function for sorting array (2 argument is method of sorting)
void array_sort(string sort_name, void (*arr_sort)(int[], int), int arr[], int size, int testNumber, ofstream& fw) {
    // Print test number
    cout << "Test number: " << testNumber << endl;
    // Write test number in file
    fw << "Test number: " << testNumber << endl;
    
    // Print sort name
    cout << sort_name << endl;
    // Write sort name in file
    fw << sort_name << endl;

    cout << "Original array" << endl;
    fw << "Original array" << endl;

    // Print original array
    results(arr, size);
    // Write original array in file
    results_out(arr, size, fw);

    try {
        // Sort array using sorting function that were passed through argument
        arr_sort(arr, size);

        cout << "Sorted array" << endl;
        fw << "Sorted array" << endl;

        // Print sorted array
        results(arr, size);
        // Write sorted array in file
        results_out(arr, size, fw);
        
        if (is_sort(arr, size)) {
            // If array is sorted
            cout << "Array was sorted correctly" << endl;
            fw << "Array was sorted correctly" << endl;
        } else {
            // If array is not sorted
            cout << "Array wasn't sorted correctly" << endl;
            fw << "Array was sorted correctly" << endl;
        }
    } catch (exception& e) {
        cout << e.what() << endl;
        fw << e.what() << endl;
    }

    // Print endline
    cout << endl;
    // Write endline
    fw << endl;
}

// Sorting array using 1 method
void sortings_start(int arr1[], int size, ofstream& fw, int testNumber) {
    // Sorting using merge sort (second argument is sort function)
    array_sort("Merge sort", merge_sort, arr1, size, 1 + testNumber, fw);
}

// Print interface
void show_interface() {
    cout << "1) Test sortings on random generated array." << endl;
    cout << "2) Test sortings on array from " << input_file << " file." << endl;
    cout << "3) Exit " << endl;
}

// Section where user generate array parsing parameters from keyboard and then sorts it
void from_keyboard(int arr1[], ofstream& fw) {
    // Get array size
    int size = try_parse("Enter array size: ", 1, true);

    // Get minimum value of array
    int minimum = try_parse("Enter minimum of array: ");

    // Get maximum value of array
    int maximum = try_parse("Enter maximum of array: ", minimum, true);

    // Create new array
    arr1 = new int[size];

    // Array generation
    array_generation(arr1, size, minimum, maximum);

    // Open file for writing
    fw.open(output_file, ios::ate);

    // Start sortings
    sortings_start(arr1, size, fw, 0);
        
    // FileStream close
    fw.close();

    // Clean memory
    delete[] arr1;
}

// Section where program gets array from file and then sorts it
void from_file(int arr1[], ofstream& fw) {
    // FileStream
    ifstream fi;
            
    // Open file
    fi.open(input_file, ios::in);

    // If file doesn't exist
    if (!fi) {
        cout << "File " << input_file << " was not found." << endl;
        return;
    }

    // Number of tests arrays
    int numArrays;

    // Get number of arrays
    fi >> numArrays;

    // Open file for writing
    fw.open(output_file, ios::ate);

    // Number of iterations = number of tests
    for (int i = 0; i < numArrays; i++) {
        // Array size
        int size;
            
        // Get array size
        fi >> size;

        // Creating new array
        arr1 = new int[size];
    
        // Reading array elements
        for (int j = 0; j < size && !fi.eof(); j++) {
            fi >> arr1[j];
        }
                
        sortings_start(arr1, size, fw, i);
                
        // Clean memory
        delete[] arr1;
    }
            
    // Close FileStream
    fw.close();

    // Close FileStream
    fi.close();
}
