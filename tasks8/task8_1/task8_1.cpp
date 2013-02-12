#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void bubbleSort(int array[], int size)
{
	bool transp = false;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				transp = true;
			}
		}
		if (!transp)
		{
			return;
		}
		transp = false;
	}
}
int main()
{
	int size = 0;
	cout << "Enter size of array: ";
	cin >> size;
	cout << endl;

	int *array = new int[size];
	srand(time(0));
	cout << "Before sorting: " << endl;
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % size;
		cout << array[i] << " | ";
	}
	cout << endl;
	bubbleSort(array, size);
	cout << "After sorting: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " | "; 
	}
	cout << endl;
	delete[] array;

	int nothing = 0;
	cin >> nothing;
	cout << endl;
	return 0;
}