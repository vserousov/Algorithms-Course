using namespace std;

/*
  This structure to provide easy way to manage items for knapsack

  You can make array of this class just like int array.

  For example: 
	  item* items = new item[6];
	  items[0] = item(55, 3);
	  items[1] = item(80, 2);
	  items[2] = item(60, 4);
	  items[3] = item(45, 1);
	  items[4] = item(105, 3);
	  items[5] = item(50, 1);
*/
struct item {
	int cost;
	int weight;

	item() {
		this->cost = 0;
		this->weight = 0;
	}

	item(int cost, int weight) {
		this->cost = cost;
		this->weight = weight;
	}
};

/*
  Class to implement some knapsack-problem algorithms.

  There are 3 algorithms to implement:
	1. Knapsack Problem via Dynamic Programming (method dynamicKnapsack)
	2. Knapsack Problem via Backtracking (method backtrackKnapsack)
	3. Knapsack Problem via Greedy Algorithm (method greedyKnapsack)

  All these methods have same signature: 
		1. item* items - array of items for knapsack (item structure is defined above)
		2. int n - number of items for knapsack
		3. int capacity - maximum capacity of knapsack.

  IMPORTANT: 1. You must implement ALL FUNCTIONS that are defined in the class
				and properly use them in the algorithm!
				ALL METHODS!
			 2. Pay attention that class have fields: items and n. This is just for
				convenience. Initialize them in methods and you will have access
				to them in other methods.
			 666: CAREFULLY READ ALL COMMENTS TO METHODS CAUSE THERE IS ALL INFORMATION 
				  WHAT TO IMPLEMENT AND HOW THERE!!!
*/
class knapsack {

public:
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
	virtual int dynamic_knapsack(item* items, int n, int capacity);
	
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
	virtual int backtrack_knapsack(item* items, int n, int capacity);

	/*
		Method to call knapsack algorthm via backtracking

		Complexity:
		1. Time: should be O(n log(n)) where n - number of items.
		2. Depends on sorting 

		Returns: approximate (but deterministic) maximum possible sum of items
		in the knapsack. (!!!)
	*/
	virtual int greedy_knapsack(item* items, int n, int capacity);

protected:
	/* Items for knapsack */
	item* items;

	/* Number of items */
	int n;
	
	/* === Methods for dynamic knapsack === */

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
	virtual int dynamic_recursive_call(int items_to_pack, int capacity, int** matrix);

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
	virtual int** make_matrix_for_dynamic(int n, int capacity);
	
	/* === Methods for backtracking knapsack === */

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
	virtual int backtracking_recursive_call(int current_item, int current_weight, int current_cost, int capacity);

	/* === Methods for greedy knapsack === */

	/*
		Method to sort items of the knapsack in the priority way.
		The priority of element is measured with value: (cost / weight).

		Complexity:
		Time: not more than O(n*log n)
		Space: depends on the sorting algorithm that you gonna choose.
	*/
	virtual void sort_items_by_priority(item* items, int n, int capacity);
};