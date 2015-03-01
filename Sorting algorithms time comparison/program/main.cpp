#include "Controller.h"

void main()
{
	ofstream myfile;
	myfile.open ("results_29_11_3.csv");

	// Vector for all sorting objects
	vector<SortingArray*> sortType;

	// Add sorting methods
	sortType.push_back(new BubbleSort());
	sortType.push_back(new BubbleIverson1());
	sortType.push_back(new BubbleIverson2());
	sortType.push_back(new InsertionSort());
	sortType.push_back(new BinarySort());
	sortType.push_back(new CountingSort());
	sortType.push_back(new RadixSort256());
	sortType.push_back(new MergeSort());
	sortType.push_back(new HeapSort());
	sortType.push_back(new QuickSortMiddle());
	sortType.push_back(new QuickSortLast());
	sortType.push_back(new ShellSort());


	for (int i = 0; i < sortType.size(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 5 && j == 1) // Don't calculate counting sort for max integer
			{
				continue;
			}

			for (int n = 1000; n <= 9000; n += 1000)
			{
				int *a = new int[n];
				Controller::create_array(a, n, j);

				int *b = new int[n];
				Controller::copy(a, b, n);

				unsigned long long average = 0;
				unsigned long long maximum = 0;

				for (int k = 0; k < 50; k++)
				{
					__int64 startTime4, endTime4;
	
					_asm
					{
						RDTSC
						mov DWORD PTR startTime4, eax
						mov DWORD PTR startTime4 + 4, edx
					}

					sortType[i]->sort(a, n);
					
					_asm
					{	
						RDTSC
						mov DWORD PTR endTime4, eax
						mov DWORD PTR endTime4 + 4, edx
					}

					__int64 diff = endTime4 - startTime4;

					average += diff;

					if (diff > maximum)
					{
						maximum = diff;
					}

					Controller::copy(b, a, n);
				}

				average = average / 50;

				myfile << n << ";"
					   << Controller::array_type(j) << ";"
					   << sortType[i]->name() << ";" 
					   << average << ";" 
					   << maximum << endl;

				cout << n << ";"
					   << Controller::array_type(j) << ";"
					   << sortType[i]->name() << ";" 
					   << average << ";" 
					   << maximum << endl;
				
				delete[] a;
				delete[] b;
			}
		}
	}

	cout << "Sortings finished..." << endl;

	vector<SortingArray*>().swap(sortType);

	myfile.close();

	system("pause");
}