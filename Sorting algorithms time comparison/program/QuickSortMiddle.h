#include "SortingArray.h"

class QuickSortMiddle: public SortingArray
{
public: 
	void sort(int a[], int n);
	string name();

private:
	void call(int a[], int left, int right);
};