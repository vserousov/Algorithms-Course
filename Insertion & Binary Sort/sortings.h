#include <iostream> //all necessary libraries
#include <ctime>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std; //standart c++ namespace

void insertion_sort(int a[], int n); //methods prototypes
void binary_sort(int a[], int n);

void array_generation(int result[], int n, int min, int max); //methods prototypes for main()
void results(int a[], int n);
bool is_sort(int a[], int n);

void copy_array(int arr1[], int arr2[], int n);
void sort_array(string sort_name, void (*arr_sort)(int[], int), int arr[], int size, int testNumber);
int try_parse(string message, int min = 0, bool minb = false, int max = 0, bool maxb = false);