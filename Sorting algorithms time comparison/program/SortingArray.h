#ifndef SORTINGARRAY_H
#define SORTINGARRAY_H

#include<iostream>
#include<string.h>
using namespace std;

class SortingArray
{
public:
	virtual ~SortingArray() {}
	virtual void sort(int a[], int n) = 0;
	virtual string name() = 0;
};

#endif