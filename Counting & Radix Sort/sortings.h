#include <iostream> //all necessary libraries
#include <ctime>
#include <Windows.h>

using namespace std; //standart c++ namespace

void counting_sort(int a[], int n); //methods prototypes
void radix_sort10(int a[], int n);
void radix_sort256(int a[], int n);

void array_generation(int result[], int n, int min, int max); //methods prototypes for main()
void results(int a[], int n);
bool is_sort(int a[], int n);