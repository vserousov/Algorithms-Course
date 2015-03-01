#include <iostream>
#include <algorithm> // For max(a, b) function.
#include "knapsack.h"

/*
 * Name: Serousov Vitaly.
 * Group: 201 SE.
 * IDE: Visual Studio 2010.
 */

/*
	Quick sort method that sorts in reversed order.
*/
void quick_sort(item items[], int left, int right) {
	int i = left;
	int j = right;

	int pivot_pos = (left + right) / 2;
	double pivot  = (double)items[pivot_pos].cost / (double)items[pivot_pos].weight;

	item temp;

	while (i <= j) {
		
		while ((double)items[i].cost / (double)items[i].weight > pivot) { // sign changed to sort in reversed order
			i++;
		}

		while ((double)items[j].cost / (double)items[j].weight < pivot) { // sign changed to sort in reversed order
			j--;
		}

		if (i <= j) {
			temp = items[i];
			items[i] = items[j];
			items[j] = temp;
			i++;
			j--;
		}
	}
	
	if (left < j) {
		quick_sort(items, left, j);
	}

	if (i < right) {
		quick_sort(items, i, right);
	}
}

/*
	Method to call knapsack algorthm via dynamic programming and using the matrix to
	store computed values.

	Complexity:
	1. Time: O(nV) where n - number of items,
	V - capacity of the knapsack.
	2. Memory: O(nV) (same as memory since we use matrix to store
	computed problems).
	Returns: maximum possible sum of items in the knapsack. (!!!)

	TIP: don't forget to delete matrix properly after the result value
	is computed.
*/
int knapsack::dynamic_knapsack(item* items, int n, int capacity) {
	this->items  = items;
	this->n      = n;
	int** matrix = make_matrix_for_dynamic(n, capacity);
	int result   = dynamic_recursive_call(n, capacity, matrix);

	for (int i = 0; i <= n; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;

	return result;
}

/*
	Method to call knapsack algorthm via backtracking

	Complexity:
	1. Time: O(nV) where n - number of items,
	V - capacity of the knapsack.
	2. Memory: O(nV) (same as memory since we use matrix to store
	computed problems).
	Returns: maximum possible sum of items in the knapsack. (!!!)

	TIP: it's not brute-force search, google "backtracking" if you are
	confused.
*/
int knapsack::backtrack_knapsack(item* items, int n, int capacity) {
	this->items = items;
	this->n     = n;
	int result  = backtracking_recursive_call(n, items[n].weight, items[n].cost, capacity);
	return result;
}

/*
	Method to call knapsack algorthm via backtracking

	Complexity:
	1. Time: should be O(n log(n)) where n - number of items.
	2. Depends on sorting 

	Returns: approximate (but deterministic) maximum possible sum of items
	in the knapsack. (!!!)
*/
int knapsack::greedy_knapsack(item* items, int n, int capacity) {
	this->items = items;
	this->n     = n;

	sort_items_by_priority(items, n, capacity);

	int total_sum = 0;

	for (int total_weight = 0, item = 0; total_weight < capacity && item < n; item++) {
		if (capacity >= items[item].weight + total_weight) {
			total_weight += items[item].weight;
			total_sum    += items[item].cost;
		}
	}

	return total_sum;
}

/*
	General method to compute knapsack problem solution via dynamic programming and using matrix.

	Params:
		items_to_pack - number of items that can be stored in the knapsack when using that method.
				        For example: call dynamic_recursive_call(5, 10, matrix) will lead to
				        the solution of knapsack problem for FIRST FIVE ITEMS with
				        the capacity of 10.

		weight - capacity of the knapsack.

		matrix - double-dimensional array to store values that are once computed.
				 There is no need to recompute the problem if it was once done.
				 So we store the results of the calls in the matrix.

	Complexity:
	1. Time: O(nV) where n - number of items,
	V - capacity of the knapsack.

	Returns: maximum possible sum of items in the knapsack.

	TIP: You MUST use the matrix to improve your running time.
*/
int knapsack::dynamic_recursive_call(int items_to_pack, int capacity, int** matrix) {

	if (matrix[items_to_pack][capacity] == 0) {
		return matrix[items_to_pack][capacity];
	}

	if (capacity >= items[items_to_pack - 1].weight) {
		int first  = dynamic_recursive_call(items_to_pack - 1, capacity, matrix);
		int second = dynamic_recursive_call(items_to_pack - 1, capacity - items[items_to_pack - 1].weight, matrix) + items[items_to_pack - 1].cost;
		matrix[items_to_pack][capacity] = max(first, second);
	} else {
		matrix[items_to_pack][capacity] = dynamic_recursive_call(items_to_pack - 1, capacity, matrix);
	}

	return matrix[items_to_pack][capacity];
}

/*
	Method to create and initialize matrix for
	knapsack algorithm via dynamic programming.

	The idea is to store calls' results in this matrix
	not to recompute the same problems multiple times
	cause it can lead to awful running time.

	Each cell contains result of the knapsack problem
	or -1 if the algorithm didn't work on these parameters.

	IMPORTANT!!!:
	So, for example item matrix[10][15] must contain:
	The result of the knapsack problem (total sum of costs)
	for 10 first items (that was parameterized in method call)
	and the maximum capacity of 15.

	Matrix should have (capacity + 1) * (items +1).
	First row (when 0 items are in the knapsack) should
	be initialized with 0 value, and other values should
	be initialized with -1.

	Complexity:
	1. Time: O(nV) where n - number of items,
		V - capacity of the knapsack.
	2. Memory: O(nV) (same as memory).

	Returns: two-dimensional array with sizes (capacity + 1) and (items + 1)

	TIP: Carefully read the whole comment before this method, cause
	multiple implementation are possible.
*/
int** knapsack::make_matrix_for_dynamic(int n, int capacity) {
	int** result = new int*[n + 1];
	for (int k = 0; k <= n; k++) {
		result[k] = new int[capacity + 1];
	}

	for (int s = 0; s <= capacity; s++) {
		result[0][s] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int s = 0; s <= capacity; s++) {
			result[k][s] = -1;
		}
	}

	return result;
}

/*
	General method to implement recursive calls for knapsack problem using backtracking.

	Params:
		current_item - index (!) of item that we now decide to put or not to put 
				(two recursive calls here)

		current_weight - sum of knapsack items' weights in the current call

		current_cost - sum of knapsack items' costs in the current call

		capacity - total capacity of the knapsack
							
	Returns: (current_cost) + (maximum possible sum of costs of items 
	with indexes in bounds [current_item, n - 1] that have sum of 
	weights less or equally to (capacity - current_weight))

*/
int knapsack::backtracking_recursive_call(int current_item, int current_weight, int current_cost, int capacity) {
	if (current_item < 0) {
		return 0;
	}

	int result;

	if (capacity >= current_weight) {
		int first  = backtracking_recursive_call(current_item - 1, items[current_item - 1].weight, items[current_item - 1].cost, capacity);
		int second = backtracking_recursive_call(current_item - 1, items[current_item - 1].weight, items[current_item - 1].cost, capacity - current_weight) + current_cost;
		result = max(first, second);
	} else {
		result = backtracking_recursive_call(current_item - 1, items[current_item - 1].weight, items[current_item - 1].cost, capacity);
	}

	return result;
}

/*
	Method to sort items of the knapsack in the priority way.
	The priority of element is measured with value: (cost / weight).

	Complexity:
	Time: not more than O(n*log n)
	Space: depends on the sorting algorithm that you gonna choose.
*/
void knapsack::sort_items_by_priority(item* items, int n, int capacity) {
	quick_sort(items, 0, n - 1);
}
