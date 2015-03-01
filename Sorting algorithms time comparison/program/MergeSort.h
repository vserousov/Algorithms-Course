#include "SortingArray.h"

class MergeSort: public SortingArray
{
public: 
	void sort(int a[], int n);
	string name();

private:
	void divide_and_merge(int* a, int l, int r);
	void merge(int *a, int l, int r);
};