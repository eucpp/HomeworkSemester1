#include "stdafx.h"

// Нерабочая версия :(

int inputN()
{
	int n = 1;
	std::cout << "Enter N (N > 1 and N < 100): ";
	std::cin >> n;
	if (n < 2)
	{
		std::cout << std::endl << "Incorrect N. Please, enter correct N > 1" << std::endl;
		n = inputN();
		return n;
	}
	return n;
}
void printSummands(int sum, int prev[], int prev_size)
{
	for (int i = 0; i < prev_size; ++i)
	{
		std::cout << prev[i] << " + ";
	}
	for (int i = 1; i <= sum; i++)
	{
		std::cout << "1 ";
		if (i != sum)
		{
			std::cout << "+ ";
		}
	}
	std::cout << std::endl;
	if (sum > 2)
	{
		for (int i = 2; i < sum; ++i)
		{

			int first = i;
			int last = 1;
			prev_size += 2;
			while (first >= last)
			{
				prev[prev_size - 2] = first;
				prev[prev_size - 1] = last;
				printSummands(sum - i, prev, prev_size);
				--first;
				++last;
			}
			std::cout << std::endl;
		}
	}
}
int main()
{
	int n = 1;
	n = inputN();

	const int maxSize = 100; 
	int buffer[maxSize] = {};
	for (int i = 1; i < maxSize; i++)
	{
		buffer[i] = 0;
	}
	printSummands(n, buffer, 0);

	std::cin >> n;
	std::cout << std::endl;
	
	return 0;
}

