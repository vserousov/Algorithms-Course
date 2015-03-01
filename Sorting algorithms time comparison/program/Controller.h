#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <limits>
#include <random>
#include <fstream>
#include "SortingArray.h"
#include "BinarySort.h"
#include "BubbleSort.h"
#include "BubbleIverson1.h"
#include "BubbleIverson2.h"
#include "CountingSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSortLast.h"
#include "QuickSortMiddle.h"
#include "RadixSort256.h"
#include "ShellSort.h"

using namespace std;

class Controller
{
public:
    static void create_array(int a[], int n, int type);
    static string array_type(int type);
    static void results(int a[], int n);
    static void copy(int a[], int b[], int n);

private:
    static int rand_number(int min, int max);
    static void swap(int a[], int i, int j);
    static void generation(int a[], int n, int min, int max);
};

#endif