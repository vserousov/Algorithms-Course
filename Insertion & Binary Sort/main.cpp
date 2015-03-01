#include "sortings.h";

/*
Name + Surname: Serousov Vitaly
Group: 201(1)SE
Date: 4.10.2014
Task: Insertion sorts
IDE: Microsoft Visual Studio 2010
*/

void main() {                                  
	//TODO: make console application, use methods in sortings file
	/*
		Note: you can add your own methods and #include's in sortings, 
		but you still need to use given methods
	*/
	/*
		Write your console application here, you need to implement next features:
		1) read data from file "test_proekt_3.txt" (which should be located in the same directory with source files);
			test_proekt_3.txt file format:
				NT //first line - number of tests
                                   // then NT times
				Ni //number of elements in i test' array   
				X1 X2 X3 ... XM //Ni elements of the array

		2) you need to output to console:
			array before sorting
			array after sorting
			result of is_sort method to sorted array

		3) check out some issues in LMS which might be not mentioned here.

		P.S.: if (IDE != Visual Studio 2010) {
					check_if_it_works_in_studio_10();
			  }
	*/
	// Unique random
	srand(time(0));

	// Exit flag
	bool exit = false;

	// Array for sorting
	static int * arr1;
	// Copy of first array
	static int * arr2;

	// Work until exit
	while (!exit) {
		// Interface
		cout << "1) Test sortings on random generated array." << endl;
		cout << "2) Test sortings on array from test_proekt_3.txt file." << endl;
		cout << "3) Exit " << endl;
	
		// Selected item from menu
		int item = try_parse("Enter item number: ", 1, true, 3, true);

		// Generate array in program
		if (item == 1) {
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

			// Create new array for copy
			arr2 = new int[size];
			// Copy array
			copy_array(arr1, arr2, size);

			// Sorting using insertion sort (2 argument is sort function)
			sort_array("Insertion sort", insertion_sort, arr1, size, 1);

			// Sorting using binary insertion sort (2 argument is sort function)
			sort_array("Binary insertion sort", binary_sort, arr2, size, 1);

			// Clean memory
			delete[] arr1;
			delete[] arr2;

		// Get testing arrays from txt
		} else if (item == 2) {
			// FileStream
			ifstream fi;
			
			// Open file
			fi.open("test_proekt_3.txt", ios::in);

			// If file doesn't exist
			if (!fi) {
				cout << "File test_proekt_3.txt was not found." << endl;
				continue;
			}

			// Number of tests arrays
			int numArrays;
			// Get number of arrays
			fi >> numArrays;

			// Number of iterations = number of tests
			for (int i = 0; i < numArrays; i++) {
				
				// Array size
				int size;
			
				// Get array size
				fi >> size;

				// Creating new array
				arr1 = new int[size];
				// Creating new array for copy
				arr2 = new int[size];

				// Reading array elements
				for (int j = 0; j < size && !fi.eof(); j++) {
					fi >> arr1[j];
				}

				// Copy filled array
				copy_array(arr1, arr2, size);
				// It's better to divide the tests with **
				cout << "**********************" << endl;
				
				// Sorting using insertion sort (2 argument is sort function)
				sort_array("Insertion sort", insertion_sort, arr1, size, i + 1);
				
				// Sorting using binary insertion sort (2 argument is sort function)
				sort_array("Binary insertion sort", binary_sort, arr2, size, i + 1);
				
				// Clean memory
				delete[] arr1;
				delete[] arr2;
			}
			// Close FileStream
			fi.close();
		} else {
			// Exit from program
			exit = true;
		}
	}
	// Pause
	system("pause");
}