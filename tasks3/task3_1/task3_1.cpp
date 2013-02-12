#include <iostream>
#include <time.h>
#include "quickSort.h"

int main()
{
	const int array_size = 20;
	int array[array_size];

	std::cout << "Random array:" << std::endl;
	
	srand(time(0));
	for (int i = 0; i < array_size; i++) 
	{
		array[i] = rand() % 10;
		std::cout << array[i] << " | ";
	}
	std::cout << std::endl;

	quickSort(array, 0, array_size - 1);

	int max = -1;
	for (int i = 0; i < array_size - 1; i++)
	{
		if(array[i] == array[i + 1])
		{
			max = array[i];
			break;
		}
	}

	if (max == -1)
	{
		std::cout << "Max repetitive element is absent";
	}
	else
	{
		std::cout << "Max repetitive element is " << max;
	}

	std::cout << std::endl;
	int n = 0;
	std::cin >> n;
	std::cout << std::endl;

	return 0;
}

