#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "heap.h"

int main()
{
	int size = 1; 
	std::cout << "Enter size of array: ";
	std::cin >> size;
	size++;
	std::cout << std::endl;

	int *array = new int[size];

	std::cout << "Before sorting" << std::endl;
	std::srand(time(0));
	for (int i = 1; i < size; i++) 
	{
		array[i] = std::rand() % 10;
		std::cout << array[i] << " | ";
	}
	std::cout << std::endl;

	heapSort(array, size - 1);

	std::cout << "After sorting:" << std::endl;
	for (int i = 1; i < size; ++i)
	{
		std::cout << array[i] << " | ";
	}
	std::cout << std::endl;
	delete []array;
	
	int n; 
	std::cin >>	n;
	return 0;
}

