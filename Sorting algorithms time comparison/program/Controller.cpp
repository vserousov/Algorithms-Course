#include "Controller.h"

void Controller::generation(int a[], int n, int minimum, int maximum)
{
    mt19937 generator;
    uniform_int_distribution<int> dist(minimum, maximum);
    for (int i = 0; i < n; i++)
    {
        a[i] = dist(generator);
        //a[i] = minimum + rand() % (maximum - minimum + 1);
    }
}

void Controller::create_array(int a[], int n, int type)
{
    srand(time(0));
    SortingArray* s;

    switch (type)
    {
        case 0:
            generation(a, n, 0, 7);
            break;

        case 1:
            generation(a, n, 0, numeric_limits<int>::max());
            break;

        case 2:
            generation(a, n, 0, 8000);
            s = new CountingSort();
            s->sort(a, n);
            delete s;
            break;

        case 3:
            generation(a, n, 0, 8000);
            s = new CountingSort();
            s->sort(a, n);
            delete s;
            for (int i = 0; i < 5; i++)
            {
                int num1 = rand_number(0, n - 1);
                int num2 = rand_number(0, n - 1);
                swap(a, num1, num2);
            }
            break;

        case 4:
            generation(a, n, 0, 8000);
            s = new CountingSort();
            s->sort(a, n);
            delete s;

            for (int i = 0; i < (n / 2); i++)
            {
                int temp = a[n - i - 1];
                a[n - i - 1] = a[i];
                a[i] = temp;
            }

            break;
    }
}

string Controller::array_type(int type)
{
    switch (type)
    {
        case 0:
            return "Random from 0 to 7";
        case 1:
            return "Random from 0 to MAX_INTEGER";
        case 2:
            return "Random from 0 to 8000 sorted";
        case 3:
            return "Random from 0 to 8000 almost sorted";
        case 4:
            return "Random from 0 to 8000 sorted reversed";
    }
}

int Controller::rand_number(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void Controller::swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void Controller::results(int a[], int n)
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i < n - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Controller::copy(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}
