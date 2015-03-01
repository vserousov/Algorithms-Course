#include "sortings.h"
#include <random>
#include <ctime>

/*
Name + Surname: Serousov Vitaly
Group: 201(1)SE
Date: 09.11.2014
Task: Quick sort
IDE: Microsoft Visual Studio 2010
*/

// This is what you need to do this time.
// Implement these functions and link their invokes together.
// All (!) functions that are not described in header should 
// be used in other functions!

// You are welcome to add some functions but NOT TO CHANGE EXISTING
// FUNCTIONS SIGNATURES.


// Quick-sort is a pivot-based sort algorithm that uses O(1) ADDITIONAL SPACE
// and works in average O(n * log(n)) time complexity. O(n * n) is the worst case.
// depth - recursion depth, leaves - number of leaves in recursion tree

// Swap 2 elements in array
void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// Quicksort with middle element in array as pivot
void quicksort::quicksort_middle(int* arr, int n, int& depth, int& leaves) {
	// TODO: Implement this method
	recursive_call_qsort(arr, 0, n - 1, get_middle_pivot, depth, leaves);
}

// Quicksort with last element in array as pivot
void quicksort::quicksort_last(int* arr, int n, int& depth, int& leaves) {
	// TODO: Implement this method
	recursive_call_qsort(arr, 0, n - 1, get_last_pivot, depth, leaves);
}

// Quicksort with random pivot
void quicksort::quicksort_rand(int* arr, int n, int& depth, int& leaves) {
	// TODO: Implement this method
	recursive_call_qsort(arr, 0, n - 1, get_rand_pivot, depth, leaves);
}

// Getting position of middle pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int quicksort::get_middle_pivot(int from, int to) {
	// TODO: Implement this method
	return (from + to) / 2;
}

// Getting position of last pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int quicksort::get_last_pivot(int from, int to) {
	// TODO: Implement this method
	return to - 1;
}

// Getting position of random pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int quicksort::get_rand_pivot(int from, int to) {
	// TODO: Implement this method
	default_random_engine generator;
	generator.seed(time(0));
	uniform_int_distribution<int> distribution(from, to - 1);
	int rand_pivot = distribution(generator);  // generates random number
	return rand_pivot;
}

// Rearranges values in the array using pivot in the current bounds
//
// Additional space: O(1)
// Complexity: O(n)
// RETURNS: new position of the pivot in the array.
int quicksort::recompute_with_pivot(int* arr, int from, int to, int pivot_pos) {
	// TODO: Implement this method
	// Current pivot
	int x = arr[pivot_pos];
	
	// Main loop 
	while (from <= to) {

		// Shift from right
		while (arr[from] < x) {
			from++;
		}

		// Shift to left
		while (arr[to] > x) {
			to--;
		}

		// Swap values and shift from and to
		if (from <= to) {
			swap(arr, from, to);
			from++;
			to--;
		}
	}

	// Return position of pivot
	return from;
}

// Recursive call for qsort that sorts the array
// in the current bounds
//
// Additional space: O(1)
// Complexity: O(n*log(n)) - average. O(n*n) - the worst case.
void quicksort::recursive_call_qsort(int* arr, int from, int to, pivot_chooser pivot_chooser, int& depth, int& leaves) {
	// TODO: Implement this method

	// Global variable in method for finding maximum of depth
	static int maxDepth = -1;

	// Flag to detect when all recursions end
	int currentDepth = maxDepth;

	// If from is less than to
	if (from < to) {

		// Get pivot position
		int x = pivot_chooser(from, to);

		// Recompute pivot position after sorting
		int pivot = recompute_with_pivot(arr, from, to, x);
		
		// If from is less than pivot - 1
		if (from < pivot - 1) {
			
			// Increase depth
			depth++;

			// If it is new maximum, update
			if (depth > maxDepth) {
				maxDepth = depth;
			}

			// Call recursive qsort for the first part of array divided by pivot
			recursive_call_qsort(arr, from, pivot - 1, pivot_chooser, depth, leaves);
		}


		// If to is more than pivot
		if (to > pivot) {

			// Increase depth
			depth++;

			// If it is new maximum, update
			if (depth > maxDepth) {
				maxDepth = depth;
			}

			// Call recursive qsort for the second part of array divided by pivot
			recursive_call_qsort(arr, pivot, to, pivot_chooser, depth, leaves);
		}

		// If "current" recursion step didn't called any recursion methods then it is leaf
		if (!(from < pivot - 1) && !(to > pivot)) {
			leaves++;
		}
	}

	// If we end recursion, then exit
	depth--;
	
	// If all recursions are finished
	if (currentDepth == -1) {

		// If maxDepth is more than 0
		if (maxDepth > 0) {
			// Then update depth
			depth = maxDepth;
		}

		// If leaves is equal or smaller zero (in case when there are just 1 element in array)
		if (leaves == 0) {
			// Then increase it
			leaves++;
		}
	}
}