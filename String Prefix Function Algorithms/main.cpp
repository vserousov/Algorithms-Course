#include <iostream>
#include <string>

using namespace std;

/*
Name + Surname: Serousov Vitaly
Group: 201(1)SE
Date: 02.12.2014
Task: String algorithms
IDE: Microsoft Visual Studio 2010
*/

// Find substring positions.
// Complexity O(n*m).
void find_substring_positions(string str, string substr);

// Find largest border.
// Complexity O(n^2).
int largest_border(string str);

// Calculate largest borders for all substrings of string starting at index 0.
// Complexity O(n^3).
void calculate_substring_borders(string str, int result[]);

// Calculate effectively largest borders for all substrings of string starting at index 0.
// Complexity O(n).
void calculate_substring_borders_effectively(string str, int result[]);

// Find substring positions effectively, Knuth-Moriss-Pratt algorithm.
// Complexity O(m + n).
void find_substring_positions_effectively(string str, string substr);

// Auxiliary functions.

// Get part of string.
string part_str(string str, int n);

// Print results of array.
void results(int arr[], int n);

// Console delimiter for output.
void cdelimiter();

// Read string data from console interface.
string read_data(string message);

// Entry point.
void main()
{
	char ch;
	do
	{
		// Task 1, O(n^2).
		cdelimiter();
		cout << "Task 1. O(n^2)" << endl;
		string str = read_data("Enter string: ");
		string substr = read_data("Enter substring: ");
		find_substring_positions(str, substr);
		cdelimiter();

		// Task 2, O(n^2).
		cout << "Task 2. O(n^2)" << endl;
		str = read_data("Enter string: ");
		int a = largest_border(str);
		cout << "Largest border length: " << a << endl;
		cout << "Largest border: " << part_str(str, a) << endl;
		cdelimiter();

		// Task 3, O(n^3).
		cout << "Task 3. O(n^3)" << endl;
		str = read_data("Enter string: ");
		int* result = new int[str.size()];
		calculate_substring_borders(str, result);
		cout << "Array of largest borders: ";
		results(result, str.size());
		delete[] result;
		cdelimiter();

		// Task 4, O(n).
		cout << "Task 4. O(n)" << endl;
		str = read_data("Enter string: ");
		result = new int[str.size()];
		calculate_substring_borders_effectively(str, result);
		cout << "Array of largest borders: ";
		results(result, str.size());
		delete[] result;
		cdelimiter();

		// Task 1, O(n + m).
		cout << "Task 1, effective realization, based on task 4. " << endl;
		cout << "Knuth-Morris-Pratt algorithm. O(n + m)." << endl;
		str = read_data("Enter string: ");
		substr = read_data("Enter substring: ");
		find_substring_positions_effectively(str, substr);
		cdelimiter();

		// Exit message.
		cout << "To exit type e." << endl;
		cout << "To continue type any symbol and press enter: ";

		// Read symbol.
		cin >> ch;

		// Flush cin.
		cin.clear();
		cin.ignore(10000, '\n');
	}
	while (ch != 'e');
}


// Find substring positions.
// Complexity O(n*m).
void find_substring_positions(string str, string substr)
{
	int count = 0;
	int n = str.size();
	int m = substr.size();

	for (int i = 0; i < n - m + 1; i++)
	{
		bool s = true;
		for (int j = 0; j < m; j++)
		{
			if (str[i + j] != substr[j])
			{
				 s = false;
				 break;
			}
		}

		if (s == true)
		{
			count++;
			cout << "Substr matches at index: " << i << endl;
		}
	}

	cout << "Number of matches: " << count << endl;
}

// Find largest border.
// Complexity O(n^2).
int largest_border(string str)
{
	int max = 0;
	int n = str.size();

	for (int i = 0; i < n; i++) 
	{
		int count = 0;
		for (int j = 0; j < i; j++) 
		{
			if (str[j] == str[n + j - i]) 
			{
				count++;
			}
			else
			{
				count = 0;
				break;
			}
		}

		if (count > max)
		{
			max = count;
		}
	}

	return max;
}

// Calculate largest borders for all substrings of string starting at index 0.
// Complexity O(n^3).
void calculate_substring_borders(string str, int result[])
{
	int n = str.size();
	for (int i = 1; i <= n; i++) // O(n)
	{
		string temp = part_str(str, i);
		result[i - 1] = largest_border(temp); // O(n^2)
	}
}

// Calculate effectively largest borders for all substrings of string starting at index 0.
// Complexity O(n).
void calculate_substring_borders_effectively(string str, int result[])
{
	int n = str.size();
	int k = 0;
	result[0] = 0;

	for (int i = 1; i < n; i++)
	{
		while ((k > 0) && (str[k] != str[i]))
		{
			k = result[k - 1];
		}

		if (str[k] == str[i])
		{
			k++;
		}

		result[i] = k;
	}
}

// Find substring positions effectively, Knuth-Moriss-Pratt algorithm.
// Complexity O(m + n).
void find_substring_positions_effectively(string str, string substr)
{
	int n = str.size();
	int m = substr.size();

	int* borders = new int[m];
	calculate_substring_borders_effectively(substr, borders); // O(m)

	int count = 0;
	int k = 0;

	for (int i = 0; i < n; i++) // O(n)
	{	
		while (substr[k] != str[i] && k > 0)
		{
			k = borders[k - 1];
		}

		if (substr[k] == str[i])
		{
			k++;
			if (k == m)
			{
				count++;
				cout << "Substr matches at index: " << i + 1 - k << endl;
				k = borders[k - 1];
			}
		}
		else
		{
			k = 0;
		}
	}

	cout << "Number of matches: " << count << endl;
	delete[] borders;
}

// Get part of string.
string part_str(string str, int n)
{
	string result = "";
	for (int i = 0; i < n; i++)
	{
		result += str[i];
	}
	return result;
}

// Print results of array.
void results(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Console delimiter for output.
void cdelimiter()
{
	cout << "\n=====================\n" << endl;
}

// Read string data from console interface.
string read_data(string message)
{
	string str;
	cout << message;
	cin >> str;
	cin.clear();
    cin.ignore(10000, '\n');
	return str;
}