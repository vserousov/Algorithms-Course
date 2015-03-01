#include <iostream>
#include <algorithm>
#include "combinatorics.h"

/*
	Combinatorics project.

	Author: Serousov Vitaly
	Group: 201 SE
	IDE: Visual Studio 2010
*/


/* 
	Auxillary functions.
*/

/*
	Factorial function (iterative).
*/
long factorial(int n) {
	// start with 1
	int result = 1;

	// mutiply to n
	for (int i = 2; i <= n; i++) {
		result *= i;
	}

	return result;
}

/*
	Function that generates permutations (recursively).
*/
void permute(vector<int> a, int next, vector<vector<int>>* result) {
	// At the last level of recursion
	if (next == a.size()) {

		// Permutation is done, so add it to result
		(*result).push_back(a);

	// Otherwise
	} else {

		// Loop through combination length
        for (int i = next; i < a.size(); i++) {

			// Swap 2 elements
            swap(a[next], a[i]);

			// Call recursively permute
            permute(a, next + 1, result);

			// Then put elements back to their positions
            swap(a[next], a[i]);
        }
    }
}

/*
	Function for checking inequality to last permutation (numbers in reversed order).
*/
bool notEq(vector<int> p) {

	// Loop through size of vector
	for (int i = 0; i < p.size() - 1; i++) {

		// If it is not in reversed order
		if (p[i] < p[i + 1]) {

			// than return true
			return true;

		}
	}

	// Otherwise return false
	return false;
}

/*
	Function that checks the existence of element in vector.
*/
bool existsElement(vector<int> a, int element) {
	// Use find function from algorithm library
	return find(a.begin(), a.end(), element) != a.end();
}

/*
	Function that generates next permutation (iteratively).
*/
vector<int> getNextPermutation(vector<int> p) {

	int n = p.size() - 1;

	// Find shift
	int i = n;
	while (i > 0 && p[i] < p[i - 1]) {
		i--;
	}

	// Find first element which is more than p[i - 1]
	int j = n;
	while (p[j] < p[i - 1]) {
		j--;
	}


	// Swap elements permutation tail in reversed order
	swap(p[i - 1], p[j]);
	for (int j = 0; j < (n - i + 1) / 2; j++) {
		swap(p[i + j], p[n - j]);
	}

	// return permutation
	return p;
}

/*
	Function that generates variation (recursively).
*/
void variate(int n, int k, vector<int> a, vector<vector<int>>* result) {

	// Check whether the combination a is filled
	if (a.size() < k) {

		// Start filling it
		for (int i = 1; i <= n; i++) {

			// It is neccesary to be filled with unique numbers
			// That's why we check for existence
			if (! existsElement(a, i)) {

				// Add number
				a.push_back(i);

				// Call recursive variation
				variate(n, k, a, result);

				// Delete number
				a.pop_back();
			}
		}

	} else {

		// If combination is filled then add to our variations vector
		(*result).push_back(a);
	}
}

/*
	Function that generates next combination (iteratively).
*/
vector<int> getNextCombination(vector<int> c, int n) {
	int k = c.size();
	int i = k - 1;
	
	// Find element which can be increased
	while (c[i] + k - i > n) {
		i--;
	}

	// Increase it
	++c[i];

	// Change elements that are in the right
	for (int j = i + 1; j < k; j++) {
		c[j] = c[j - 1] + 1;
	}

	// Return combination
	return c;
}

/*
	Function that generates summands (recursively).
*/
void recursiveSummands(int n, int i, vector<int> summand, vector<vector<int>>* result) {
	// If sum of elements in summand is equal to n, so it is equal to n == 0
	if (n == 0) {
		
		// than add summand to our collection of summands
		(*result).push_back(summand);

	// Otherwise
	} else {

		// Start loop from the biggest number possible (maximum number that can be added to summand)
		for (int j = i; j > 0; j--) {

			// It can be added only if this number is not bigger than n
			if (j <= n) {

				// Add number to summand
				summand.push_back(j);

				// Call recursively summand but distract j from n, because we added it to collection
				recursiveSummands(n - j, j, summand, result);

				// Delete number from summand
				summand.pop_back();
			}
		}
	}
}

/*
	Methods implementation of combinatorics class.
*/

/*
	Method to get number of permutations of n items

	Params:
		n - number of items to be permuted
	Returns:
		number of permutations of n items or 0 if n <= 0
*/
long combinatorics::numberOfPermutations(int n) {
	// precondition
	if (n <= 0) {
		return 0;
	}

	// number of permutations is equal to n!
	return factorial(n);
}

/*
	Method to get number of variations of k items in a set of n items

	Params:
		n - number of all items
		k - number of items in a single variation
	Returns:
		number of variations of k items in a set of n items or 0 if n <= 0 or k <= 0 or k > n
*/
long combinatorics::numberOfVariations(int n, int k) {
	// precondition
	if (n <= 0 || k <= 0 || k > n) {
		return 0;
	}
	
	// number of variations is equal to A(n) = n! / (n - k)!
	return factorial(n) / factorial(n - k);
}

/*
	Method to get number of combinations of k items in a set of n items

	Params:
		n - number of all items
		k - number of items in a single combination 
	Returns:
		number of combinations of k items in a set of n items or 0 if n <= 0 or k <= 0 or k > n
*/
long combinatorics::numberOfCombinations(int n, int k) {
	if (n <= 0 || k <= 0 || k > n) {
		return 0;
	}
	
	// number of combinations is equal to C_n^k = n! / (k! * (n - k)!)
	return factorial(n) / (factorial(k) * factorial(n - k));
}

/*
	Method to retrieve all permutaions of n items with recursive algorithm

	Params:
		n - number of items to be permuted
	Returns:
		vector of permutations (which are represented by vectors). result.size should be equal to number of permutations of n,
		each permutation should have the same length equal to n.
*/
vector<vector<int>> combinatorics::getAllPermutationsRecursive(int n) {
	// resulting vector of permutations
	vector<vector<int>> result;
	
	// generate first permutation
	vector<int> a;
	for (int i = 1; i <= n; i++) {
		a.push_back(i);
	}

	// call permute function
	permute(a, 0, &result);

	// return vector of permutations
	return result;
}

/*
	Method to retrieve all permutaions of n items with iterative algorithm

	Params:
		n - number of items to be permuted
	Returns:
		vector of permutaions (which are represented by vectors). result.size should be equal to number of permutations of n,
		each permutation should have the same length equal to n.
*/
vector<vector<int>> combinatorics::getAllPermutationsIterative(int n) {
	// resulting vector of permutations
	vector<vector<int>> result;

	// generate first permutation
	vector<int> a;
	for (int i = 1; i <= n; i++) {
		a.push_back(i);
	}

	// add it to result vector
	result.push_back(a);

	// while permutation is not a reversed sorted array (last permutation)
	while (notEq(a)) {

		// generate new permutation
		a = getNextPermutation(a);

		// add it to result
		result.push_back(a);
	}

	// return vector of permutations
	return result;
}

/*
	Method to retrieve all variations of k items in a set of n items

	Params:
		n - total number of items
		k - number of items in a single variation
	Returns:
		vector of variations (which are represented by vectors). result.size should be equal to number of variations of k in n,
		each variation should have the same length equal to k.
*/
vector<vector<int>> combinatorics::getAllVariations(int n, int k) {
	// resulting vector of variations
	vector<vector<int>> result;

	// vector for variation
	vector<int> a;

	// generate variations
	variate(n, k, a, &result);

	// return vector of variations
	return result;
}

/*
	Method to retrieve all combinations of k items in a set of n items

	Params:
		n - total number of items
		k - number of items in a single combination
	Returns:
		vector of combinations (which are represented by vectors). result.size should be equal to number of combinations of k in n,
		each combination should have the same length equal to k.
*/
vector<vector<int>> combinatorics::getAllCombinations(int n, int k) {
	// resulting vector of combinations
	vector<vector<int>> result;

	// generate first combination
	vector<int> a;
	for (int i = 1; i <= k; i++) {
		a.push_back(i);
	}

	// add combination to result
	result.push_back(a);
	
	// get total number of combinations
	int total = combinatorics::numberOfCombinations(n, k);

	// generate total - 1 combinations (because first combination created before)
	for (int i = 1; i < total; i++) {
		a = getNextCombination(a, n);
		result.push_back(a);
	}

	// return number of combinations
	return result;
}

/*
	Method to return all vectors of summands in non-increasing order of n.

	Params:
		n - value which is sum of summands in result vectors.

	Returns:
		vector of all possible partitions to summands. Sum of summands in each vector of the result vector should be equal to n.
		Summands in each vector of the result vector should be in non-increasing order.
		Size of the result vector should be equal to number of all possible representations of n via sum of summands in non-increasing order.
*/
vector<vector<int>> combinatorics::getAllSummands(int n) {
	// resulting vector of summands
	vector<vector<int>> result;

	// vector of summand
	vector<int> a;

	// generate summands
	recursiveSummands(n, n, a, &result);

	// return vector of summands
	return result;
}