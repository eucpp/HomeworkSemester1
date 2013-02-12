#include <stdlib.h>
#include <iostream>

int main()
{
	const int n = 5;
	int array[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = i * n + j + 1;
		}
	}

	int row = n / 2;
	int col = n / 2;
	bool direction = true; // true - rigth & up; false - left & down
	std::cout << "Spiral:" << std::endl;
	std::cout << array[row][col] << " | ";
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (direction)
			{
				col++;
			}
			else
			{
				col--;
			}
			std::cout << array[row][col] << " | ";
		}
		for (int j = 1; j <= i; j++)
		{
			if (direction)
			{
				row--;
			}
			else
			{
				row++;
			}
			std::cout << array[row][col] << " | ";
		}
		direction = !direction;
	}
	for (int i = 1; i < n; ++i)
	{
		col++;
		std::cout << array[row][col] << " | ";
	}
	std::cout << std::endl;
	

	int c;
	std::cin >> c;
	std::cout << std::endl;
	return 0;
}