#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
 * Author: Serousov Vitaly.
 * Group: 201 SE.
 * IDE: Visual Studio 2010.
 */

void results(int arr[], int n);
void cdelimiter();
string read_data(string message);
void calculate_substrings_borders(string str, string substr, int result[]);
int comparison(int p1, int p2, string str);
void calculate_block_effective(string str, int blocks[]);
void concatenate_and_print(string str, string substr);
void print_all_substrings_borders(int substr_size, int results[], int n);
void print_all_substrings_blocks(int substr_size, int results[], int n);
void blocks_print(string str, int blocks[]);
void task5();
void task6();
void task7();
void task8();

// Main method
void main()
{
	while (true) 
	{
		// call task 5
		task5();

		// call task 6
		task6();

		// call task 7
		task7();
		
		// call task 8
		task8();

		// inform user
		cout << "For exit type 0: " << endl;

		// read char from console
		char c = getchar();
		
		// if 0 is typed then exit
		if (c == '0')
		{
			break;
		}
	}
}

// Task 5 solution
void task5()
{
	// print task number in console
	cout << "Task 5" << endl;
	
	// read string and substring from console
	string str    = read_data("Enter string:");
	string substr = read_data("Enter substring:");
	
	// get size of possible concatenated string
	int rsize = str.size() + substr.size() + 1;

	// initialize a pointer to array of borders
	int* result = new int[rsize];

	// calculate borders
	calculate_substrings_borders(str, substr, result);

	// print concatenated string
	concatenate_and_print(str, substr);

	// print array of borders
	results(result, rsize);

	// print all substrings using array of borders
	print_all_substrings_borders(substr.size(), result, rsize);
		
	// clean memory
	delete[] result;

	// console delimiter for tasks
	cdelimiter();
}

// Task 6 solution
void task6()
{
	// print task number in console
	cout << "Task 6." << endl;

	// read string from console
	string str = read_data("Enter string:");

	// print message in console
	cout << "Array of block sizes: " << endl;
	
	// get size of string
	int n = str.size();

	// initialize a pointer to array of blocks
	int* blocks = new int[n];

	// generate array of blocks using comparison
	for (int i = 0; i < str.size(); i++) 
	{
		blocks[i] = comparison(0, i, str);
	}
	
	// print array of blocks
	results(blocks, n);

	// print blocks
	blocks_print(str, blocks); 

	// clean memory
	delete[] blocks;

	// console delimiter
	cdelimiter();
}

// Task 7 solution
void task7()
{
	// print task number in console
	cout << "Task 7." << endl;

	// read string from console
	string str = read_data("Enter string:");

	// print message in console
	cout << "Array of block sizes: " << endl;
	
	// get size of string
	int n = str.size();

	// initalize pointer to array of blocks
	int* blocks = new int[n];
	
	// calculate array of blocks effective using array of blocks
	calculate_block_effective(str, blocks);

	// print array of blocks
	results(blocks, n);

	// clean memory
	delete[] blocks;

	//console delimiter
	cdelimiter();
}

// Task 8 solution
void task8()
{
	// print task number in console
	cout << "Task 8." << endl;

	// get string and substring from console
	string str    = read_data("Enter string:");
	string substr = read_data("Enter substring:");

	// concatenate substring and string with $
	string concatenated = substr + "$" + str;

	// get size of concatenated string
	int n = concatenated.size();

	// initialize pointer to array of blocks
	int* blocks = new int[n];

	// call effective block calculation
	calculate_block_effective(concatenated, blocks);

	// print message in console
	cout << "\nConcatenated string and substring, array of blocks: " << endl;

	// concatenate and print string, substring and $ between them with spaces
	concatenate_and_print(str, substr);

	// print array of blocks
	results(blocks, n);

	// print all substrings using array of blocks
	print_all_substrings_blocks(substr.size(), blocks, n);

	// clean memory
	delete[] blocks;

	// print console delimiter
	cdelimiter();
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

// Complexity O(n).
void calculate_substrings_borders(string str, string substr, int result[])
{
	// concatenate substring and string
	string concat = substr + "$" + str;

	// get length of concatenated string
	int n = concat.size();

	// k starts with 0
	int k = 0;

	// border for first element is equal to 0
	result[0] = 0;

	for (int i = 1; i < n; i++)
	{
		// get value from previous border
		while ((k > 0) && (concat[k] != concat[i]))
		{
			k = result[k - 1];
		}

		// increase if border is becoming larger
		if (concat[k] == concat[i])
		{
			k++;
		}

		// update result
		result[i] = k;
	}
}

// Comparison function
int comparison(int p1, int p2, string str)
{
	// substring that is equal to string has 0 block
	if (p1 == p2)
	{
		return 0;
	}

	// initialize counter
	int count = 0;

	// i starts with p1 and j starts with p2
	for (int i = p1, j = p2; i < str.size() && j < str.size(); i++, j++)
	{
		if (str[i] != str[j])
		{
			// stop when symbols are different
			break;
		}
		else
		{
			// increase counter
			count++;
		}
	}

	// return result
	return count;
}

// Effective block calculation
void calculate_block_effective(string str, int blocks[])
{
	int n = str.size();
	int r = 0;
	int l = 0;
	blocks[0] = 0;
	for (int i = 1; i < n; i++)
	{
		blocks[i] = 0;
		if (i > r)
		{
			blocks[i] = comparison(0, i, str);
			// count the length of substrings matches and update l and f, if there is a match 
			if (blocks[i] > 0)
			{
				r = i + blocks[i] - 1;
				l = i;
			}
		}
		else
		{
			// position i is in block
			int k = i - l;
			if (blocks[k] < r - i + 1)
			{
				blocks[i] = blocks[k];
			}
			else
			{
				// the size of block in position k is greater than the last part of block, that covers position i
				blocks[i] = r - i + 1;
				l = i;
				int q = comparison(r - i + 1, r + 1, str);
				if (q > 0)
				{
					// if there is match, determine the size of block and his right border
					blocks[i] = blocks[i] + q;
					r = i + blocks[i] - 1;
				}
			}
		}
	}
}

// Concatenate string and print it with spaces
void concatenate_and_print(string str, string substr) 
{
	cout << "\nConcatenated string and substring, array of borders: " << endl;
	// concatenate substring and string
	string result = substr + "$" + str;

	// printing the result with spaces
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
}

// Print all substrings using array of borders
void print_all_substrings_borders(int substr_size, int results[], int n)
{
	// initalize counter
	int count = 0;

	cout << "Matches start at the beginning of string (Not substring and not concatenation):" << endl;
	
	// find matches when the length of border is equal to length of substring
	bool matched = false;
	for (int i = 0; i < n; i++)
	{
		if (results[i] == substr_size)
		{
			cout << "Substr matches at " << (i - 2 * substr_size) << " index of string" << endl;
			count++;
			matched = true;
		}
	}
	
	// if no matches
	if (!matched)
	{
		cout << "No matches" << endl;
		return;
	}

	// total number of matches
	cout << "Total number of matches: " << count << endl;
}

// Print all substrings using array of blocks
void print_all_substrings_blocks(int substr_size, int results[], int n)
{
	// initalize counter
	int count = 0;

	cout << "Matches start at the beginning of string (Not substring and not concatenation):" << endl;

	// find matches when the length of border is equal to length of substring
	bool matched = false;
	for (int i = 0; i < n; i++)
	{
		if (results[i] == substr_size)
		{
			cout << "Substr matches at " << (i - substr_size - 1) << " index of string" << endl;
			count++;
			matched = true;
		}
	}

	// if no matches
	if (!matched)
	{
		cout << "No matches" << endl;
		return;
	}

	// total number of matches
	cout << "Total number of matches: " << count << endl;
}

// Print all blocks using array
void blocks_print(string str, int blocks[])
{
	cout << "\nNon-empty blocks: " << endl;

	for (int i = 0; i < str.size(); i++) 
	{
		// print block if it has size greater than 0
		if (blocks[i] > 0)
		{
			for (int j = 0; j < blocks[i]; j++)
			{
				cout << str[j];
			}
			
			cout << " (at index " << i << ")" << endl;
		}
	}
}