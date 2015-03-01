#include "SortingArray.h"

class HeapSort: public SortingArray
{
public: 
	void sort(int a[], int n);
	string name();

private:
	void buildHeap(int a[], int n);
	void heapify(int a[], int n, int i);
	int right(int i);
	int left(int i);
};