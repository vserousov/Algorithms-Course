#include "sortings.h";

/*
Name + Surname: Сероусов Виталий
Group: 201(1)ПИ
Date: 29.09.2014
Task: Функции сортировки пузырьком
IDE: Microsoft Visual Studio 2013
*/

void main() {                                  
    //TODO: make console application, use methods in sortings file
    /* User must have possibility to:
        1) generate array;
        2) sort array using bubble sort;
        3) sort array using bubble sort with Iverson I;
        4) sort array using bubble sort with Iverson II;
        5) output result (array before sorting and after);
        6) exit.
        P.S: while new array isn't generated, you need to sort previous generated array (which is not sorted)
    */
    // To make unique arrays
    srand(time(0));
    // Input array
    int* inputArr = NULL;
    // Result array
    int* resultArr = NULL;
    // Size of array
    int size;
    do 
    {
        // User interface
        cout << "Interface: " << endl;
        cout << "1) generate array" << endl;
        cout << "2) sort array using bubble sort" << endl;
        cout << "3) sort array using bubble sort with Iverson I" << endl;
        cout << "4) sort array using bubble sort with Iverson II" << endl;
        cout << "5) exit" << endl;
        cout << "\nEnter the number: ";

        // Get number
        int in;
        cin >> in;

        // Flag to exit
        bool exit = false;

        // If the number was parsed
        if (!cin.fail()) {
            // Generating array
            if (in == 1) {
                int min;
                int max;

                // Parse array size
                do {
                    // Clear thread
                    cin.clear();
                    cin.ignore(10000, '\n');
                    // Get data from keyboard
                    cout << "\nEnter array size (more than 1): ";
                    cin >> size;
                }
                while (cin.fail() || size <= 1);

                // Parse minimum array value
                do {
                    // Clear thread
                    cin.clear();
                    cin.ignore(10000, '\n');
                    // Get data from keyboard
                    cout << "\nEnter minimum value of array: ";
                    cin >> min;
                } while (cin.fail());

                // Parse maximum array value
                do {
                    // Clear thread
                    cin.clear();
                    cin.ignore(10000, '\n');
                    // Get data from keyboard
                    cout << "\nEnter maximum value of array: ";
                    cin >> max;
                } while (cin.fail() || max <= min);

                // Create array
                inputArr = new int[size];

                // Generate random array that is not sorted
                do {
                    array_generation(inputArr, size, min, max);
                } 
                while (is_sorted(inputArr, size));

                // Copying to result array
                resultArr = new int[size];
                for (int i = 0; i < size; i++) {
                    resultArr[i] = inputArr[i];
                }

                // Message to interface
                cout << "Array successfully generated" << endl;
            }
            // Sort array
            else if (in >= 2 && in <= 4) {
                // If there is no array
                if (inputArr == NULL) {
                    cout << "Create array before sorting it." << endl;
                }
                // If there is array
                else {
                    switch (in) {
                        // Bubble            
                        case 2:
                            cout << "\n Bubble Sort" << endl;
                            bubble_sort(resultArr, size);
                            break;
                        // Iverson 1
                        case 3:
                            cout << "\n Bubble Iverson 1 Sort" << endl;
                            bubble_iverson_1(resultArr, size);
                            break;
                        // Iverson 2
                        case 4:
                            cout << "\n Bubble Iverson 2 Sort" << endl;
                            bubble_iverson_2(resultArr, size);
                            break;
                        // Invalid
                        default:
                            break;
                    }

                    // Printing array before and after sorting
                    cout << "\nArray before sorting" << endl;
                    results(inputArr, size);
                    cout << "\nArray after sorting" << endl;
                    results(resultArr, size);

                    // Copy input array to result array in case of sort in another method
                    for (int i = 0; i < size; i++) {
                        resultArr[i] = inputArr[i];
                    }
                }
            }
            // Exit from program
            else if (in == 5) {
                    exit = true;
                    // Clear memory
                    delete[] inputArr;
                    delete[] resultArr;
            }
            // Invalid number
            else {
                cout << "\nNumber must be between 1 and 6.\n" << endl;
            }
        }
        // Invalid number
        else {
            cout << "\nIncorrect number, it must be integer.\n" << endl;
        }

        // Exit from program
        if (exit == true) {
            break;
        }

        // Empty line for readability
        cout << endl;

        // Clear thread
        cin.clear();
        cin.ignore(10000, '\n');
    } while (true);
}
