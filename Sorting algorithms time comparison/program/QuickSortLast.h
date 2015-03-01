#include "SortingArray.h"

class QuickSortLast: public SortingArray
{
public: 
	void sort(int a[], int n);
	virtual string name();

private:
	void call(int a[], int left, int right);
};