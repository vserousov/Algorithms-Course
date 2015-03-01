#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
 * Author: Serousov Vitaly
 * Group: 201 SE
 * IDE: Visual Studio 2010
 */

void make_decision(int min_left_bank[], int min_right_bank[], int prev_left[], int prev_right[], int i, int c);
void get_prev(int a[], int i);

ifstream input("input_bridge.txt");
ofstream output("output_bridge.txt");

void main()
{
	string inflows;
	input >> inflows;
	int number = inflows.size();

	int* min_left_bank = new int[number];
	int* min_right_bank = new int[number];
	int* prev_left = new int[number];
	int* prev_right = new int[number];

	// Starts from left bank
	min_left_bank[0] = 0;
	min_right_bank[0] = 1;
	prev_left[0] = 0;
	prev_right[0] = 0;

	for (int i = 1; i <= number; i++)
	{
		char symbol = inflows[i - 1];

		get_prev(min_left_bank, i);
		get_prev(min_right_bank, i);
		get_prev(prev_left, i);
		get_prev(prev_right, i);

		make_decision(min_left_bank, min_right_bank, prev_left, prev_right, i, symbol);

		if (min_left_bank[i - 1] == 0) {
			get_prev(min_left_bank, i);
			++min_left_bank[i];
		}

		if (min_right_bank[i - 1] == 1) {
			get_prev(min_right_bank, i);
			++min_right_bank[i];
		}

		if (min_left_bank[i] + 1 < min_right_bank[i]) {
			min_right_bank[i] = min_left_bank[i] + 1; 
		}
	
		if (min_right_bank[i] + 1 < min_left_bank[i]) {
			min_left_bank[i] = min_right_bank[i] + 1;
		}
	}

	cout << min_right_bank[number] << endl;
	output << min_right_bank[number];
	system("pause");
}

void make_decision(int min_left_bank[], int min_right_bank[], int prev_left[], int prev_right[], int i, int c) {
	switch (c) {
		// Cross the inflow on the left bank
		case 'L':
			min_left_bank[i] = min_left_bank[prev_left[i - 1]] + 1;
			prev_left[i] = i;
			break;

		// Cross the inflow on the right bank
		case 'R':
			min_right_bank[i] = min_right_bank[prev_right[i - 1]] + 1;
			prev_right[i] = i;
			break;

		// Inflow both on left and right bank
		case 'B':
			min_left_bank[i] = min_left_bank[prev_left[i - 1]] + 1;
			min_right_bank[i] = min_right_bank[prev_right[i - 1]] + 1;
			prev_left[i] = prev_right[i] = i;
			break;

		// Illegal character
		default:
			cout << "Illegal symbol" << endl;
			break;
	}
}

void get_prev(int a[], int i) {
	a[i] = a[i - 1];
}