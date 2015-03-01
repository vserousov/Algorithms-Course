#include<iostream>
#include<string>
#include<fstream>

using namespace std;

/*
Name + Surname: Serousov Vitaly
Group: 201(1)SE
Date: 06.11.2014
Task: Prefix notation
IDE: Microsoft Visual Studio 2010
*/

// Function prototypes
int try_parse(string message, int min = 0, bool minb = false, int max = 0, bool maxb = false);
int prefix_notation(string input, int& position);
string parse_console();
string parse_file();
void show_menu();
bool is_operation(char symbol);
bool data_verification(string str);

// Input filename
const string input_file = "AddPr_2.txt";

void main() 
{
	// Set charset
	setlocale(LC_ALL, "Russian");
	
	// Show menu
	show_menu();
	
	// Main loop
	while (true) 
	{
		// Parse menu item
		int item = try_parse("Введите номер режима: ", 1, true, 3, true);
		
		// Starting position
		int position = -1;
		
		// Result of function
		int result;

		// Parsed string
		string str;

		switch (item) 
		{	
			// From console
			case 1:
				str = parse_console();
				break;

			// From file
			case 2:
				str = parse_file();
				cout << "Файл содержит следующую строку:" << str << endl;
				break;

			// Exit
			case 3:
				return;
		}

		// Data verification
		if (!data_verification(str))
		{
			cout << "Ошибка во входных данных. " << endl;
			cout << "Строка не должна начинаться или заканчиваться пробелом." << endl;
			cout << "В строке допустимы только следующие символы: +-*/%0123456789 и символ пробела." << endl;
			continue;
		}

		// Calculate result
		result = prefix_notation(str, position);

		// Return result
		cout << "Результат выполнения операции: " << result << endl;
	}
}

// Show menu
void show_menu()
{
	cout << "1) Ввести префиксное выражение с консоли" << endl;
	cout << "2) Ввести префиксное выражение из текстового файла " << input_file << endl;
	cout << "3) Выход" << endl;
}

// Data verification method
bool data_verification(string str)
{
	int position = 0;
	int count_digits = 0;
	int count_operations = 0;

	// If there is only one symbol
	if (str.length() == 1 && isdigit(str[0]))
	{
		return true;
	}

	// Check if there are no symbols except whitespace, number or operation
	for (int i = 0; i < str.length(); i++) 
	{
		if (!(str[i] == ' ' || isdigit(str[i]) || is_operation(str[i])))
		{
			return false;
		}
	}

	int length = str.length();

	// Check if last symbol is digit
	if (!isdigit(str[length - 1])) 
	{
		return false;
	}

	// Check if first symbol is not whitespace
	if (str[0] == ' ')
	{
		return false;
	}

	// Counting number of digits and operations
	while (position < length)
	{
		if (isdigit(str[position]))
		{
			count_digits++;
		} 
		else if (is_operation(str[position])) 
		{
			count_operations++;
		} 
		else
		{
			return false;
		}

		int prev = position;
		int find = str.find(' ', position);

		if (find != std::string::npos) 
		{
			position = str.find(' ', position) + 1;
		}
		else
		{
			break;
		}
	}

	// Get result (True if count digits is more by 1 then operations, otherwise false)
	bool result = count_digits == count_operations + 1;
	return result;
}

// Check if symbol is operation
bool is_operation(char symbol) 
{
	switch (symbol)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			return true;
		
		default:
			return false;
	}
}

// Parse from console
string parse_console()
{
	// Result
	string result;

	// Print message to console
	cout << "Введите префиксное выражение: ";

	// Read line from console
	getline(cin, result);

	// Return result
	return result;
}

// Parse from file
string parse_file()
{
	// Result
	string result;

	// FileStream
	ifstream fi;

	// Open file
	fi.open(input_file, ios::in);

	// Get line
	getline(fi, result);

	// Close file
	fi.close();

	// Return result
	return result;
}

// Prefix notation recursion method
int prefix_notation(string str, int& position)
{
	// If there is only one digit return it
	if (str.length() == 1)
	{
		return stoi(str);
	}

	// Find next space
	int space = str.find(' ', position + 1);
	
	// Get substring
	string s = str.substr(position + 1, space - position);

	// Update current position
	position = space;

	// If it is digit convert it to int and return
	if (isdigit(s[0]))
	{
		return stoi(s);
	}
	else
	{
		// Calculate recursive first number
		int numb1 = prefix_notation(str, position);

		// Calculate recursive second number
		int numb2 = prefix_notation(str, position);

		// Operation switch and calculate
		switch (s[0]) 
		{
			case '+':
				return numb1 + numb2;

			case '-':
				return numb1 - numb2;

			case '*':
				return numb1 * numb2;

			case '/':
				return numb1 / numb2;

			case '%':
				return numb1 % numb2;
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