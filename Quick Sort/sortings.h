using namespace std;

// Pivot chooser function type
typedef int(*pivot_chooser) (int from, int to);

class quicksort {

public:

    // Sorting methods
    static void quicksort_middle(int* arr, int n, int& depth, int& leaves);
    static void quicksort_last(int* arr, int n, int& depth, int& leaves);
    static void quicksort_rand(int* arr, int n, int& depth, int& leaves);

private:

    // Auxiliary methods
    static int get_middle_pivot(int from, int to);
    static int get_last_pivot(int from, int to);
    static int get_rand_pivot(int from, int to);
    static int recompute_with_pivot(int* arr, int from, int to, int pivot_pos);
    static void recursive_call_qsort(int* arr, int from, int to, pivot_chooser pivot_chooser, int& depth, int& leaves);
};

