#include <iostream> //all necessary libraries
#include <ctime>
#include <Windows.h>

using namespace std; //standart c++ namespace

void bubble_sort(int a[], int n); // methods prototypes
void bubble_iverson_1(int a[], int n);
void bubble_iverson_2(int a[], int n);

void array_generation(int result[], int n, int min, int max); //methods prototypes for main()
void results(int a[], int n);
bool is_sorted(int a[], int n);