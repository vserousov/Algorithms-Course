#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/*
Name + Surname: Serousov Vitaly
Group: 201(1)SE
Date: 19.12.2014
Task: Knuth-Moriss-Pratt algorithm
IDE: Microsoft Visual Studio 2010
*/

/* Function prototypes. */

// Calculate effectively largest borders for all substrings of string starting at index 0.
// Complexity O(n).
void calculate_borders(string str, int result[]);

// Find substring positions effectively, Knuth-Moriss-Pratt algorithm.
// Complexity O(m + n).
void find_substrings(string str, string substr);

// Auxiliary functions.

// Print results of array.
void results(int arr[], int n);

// Print results of vector.
void results(vector<int> arr);

// Output results
void output_results(string str, string substr, int borders[], vector<int> positions, vector<int> comparisons, vector<int> matches);

// Read string data from console interface.
string read_data(string message);

// Read string data from console interface.
char read_symbol(string message);

// Print menu to console interface
void menu();

// Read from console
void from_console();

// Read from file
void from_file();

// Input filename
const string input_filename  = "input12.txt";

// Output filename
const string output_filename = "output12.txt";

// Input filestream
ifstream input;

// Output filestream
ofstream output;

// Entry point.
void main()
{
	while (true) {
		menu();
		char method = read_symbol("Enter menu item number: ");
		if (method == '1') {
			from_console();
		} else if (method == '2') {
			from_file();
		} else {
			break;
		}
	}
}

// Calculate effectively largest borders for all substrings of string starting at index 0.
// Complexity O(n).
void calculate_borders(string str, int result[]) {
	int n = str.size();
	int k = 0;
	result[0] = 0;

	for (int i = 1; i < n; i++) {

		while ((k > 0) && (str[k] != str[i])) {
			k = result[k - 1];
		}

		if (str[k] == str[i]) {
			k++;
		}

		result[i] = k;
	}
}

// Find substring positions, Knuth-Moriss-Pratt algorithm.
// Complexity O(m + n).
void find_substrings(string str, string substr) {

	// Length of string
	int n = str.size();

	// Length of substring
	int m = substr.size();

	// Array of borders
	int* borders = new int[m];

	// Generate array of borders
	calculate_borders(substr, borders); // O(m)

	// Starting positions
	vector<int> positions;

	// Starting positions of comparisons
	vector<int> comparisons;

	// Indexes of matches
	vector<int> matches;

	// Start with i = 0
	int i = 0;

	// Start with k = 0
	int k = 0;
	
	// Loop while the position of last element of substring is less than n
	while (i + (m - 1) < n) {

		// Add starting position
		positions.push_back(i);

		// Add starting comparison position
		comparisons.push_back(i + k);
		
		// Flag for substr finding
		bool found = false;

		// Loop while i + k is not upper bound and while substr symbol is equal to str symbol
		while (i + k < n && substr[k] == str[i + k]) {

			// If we haven't check all symbols
			if (k != (m - 1)) {

				// Then increase k
				k++;

			// Situation where all symbols equals to each other respectively
			} else {
				
				// So that substring was found in string
				found = true;
				break;
			}
		}

		// If substring was found
		if (found) {

			// Add index of match
			matches.push_back(i);
		}

		// If the first symbol of substr is equal to string
		if (k != 0) {

			// Move by shift k - borders[k - 1]
			i += k - borders[k - 1];

			// Update k for skipping unnecessary comparison
			if (! found) {

				// When element was found we need to move by 1 element more
				k = borders[k - 1];
			} else {

				// Otherwise we need to move by border number of element
				k = borders[k - 1] + 1;
			}

		// Otherwise
		} else {

			// Then move by 1 position
			i += 1;
		}
	}

	// Print results to console and to file
	output_results(str, substr, borders, positions, comparisons, matches);

	// Delete border array
	delete[] borders;
}

// Print results of array.
void results(int arr[], int n) {
	for (int i = 0; i < n; i++)  {
		output << arr[i] << " ";
		cout   << arr[i] << " ";
	}	
	
	output << endl;
	cout   << endl;
}

// Print results of vector.
void results(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		output << arr[i] << " ";
		cout   << arr[i] << " ";
	}

	output << endl;
	cout   << endl;
}

// Read string data from console interface.
string read_data(string message) {
	string str;
	cout << message;
	cin >> str;
	cin.clear();
    cin.ignore(10000, '\n');
	return str;
}

// Read symbol from console interface
char read_symbol(string message) {
	char s;
	cout << message;
	cin >> s;
	cin.clear();
	cin.ignore(10000, '\n');
	return s;
}

// Print menu to console interface
void menu() {
	cout << "1) Enter string and substring from console. " << endl;
	cout << "2) Get strings and substrings from input12.txt. " << endl;
	cout << "For exit type any key. " << endl;
}


// Read from console
void from_console() {
	output.open(output_filename, ios::ate);
	string str    = read_data("Enter string: ");
	string substr = read_data("Enter substring: ");
	find_substrings(str, substr);
	output.close();
}

// Read from file
void from_file() {
	input.open(input_filename);
	output.open(output_filename, ios::ate);
	int numTests;
	input >> numTests;
	
	for (int i = 0; i < numTests; i++) {
		cout   << "Test " << i + 1 << endl;
		output << "Test " << i + 1 << endl;
		string str;
		string substr;
		input >> str;
		input >> substr;
		find_substrings(str, substr);
	}

	output.close();
	input.close();
}


// Output results
void output_results(string str, string substr, int borders[], vector<int> positions, vector<int> comparisons, vector<int> matches) {
	output << "T = " << str << endl;
	cout   << "T = " << str << endl;
	
	output << "P = " << substr << endl;
	cout   << "P = " << substr << endl;

	results(borders, substr.size());
	results(positions);
	results(comparisons);
	results(matches);
	
	output << matches.size() << endl;
	cout   << matches.size() << endl;
}