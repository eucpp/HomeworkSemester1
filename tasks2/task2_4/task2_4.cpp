#include "stdafx.h"
#include <iostream>

int inputN()
{
	int n = 1;
	std::cout << "Enter N (N > 1 and N < 100): ";
	std::cin >> n;
	if ((n < 2) || (n > 99))
	{
		std::cout << std::endl << "Incorrect N. Please, enter correct N." << std::endl;
		n = inputN();
		return n;
	}
	return n;
}
void printFraction(int fractions[], int i)
{
	std::cout << " " << fractions[i] << "/" << i << " ";
}
int minFraction(int fractions[], int a, int b)
{
	int prod1 = a * fractions[b];
	int prod2 = b * fractions[a];
	if (prod2 <= prod1)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int gcd(int a, int b)
{
	int r = a % b;
	if (r == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, r);
	}
}
bool isIrredFraction(int fractions[], int a)
{
	int rem = gcd(a, fractions[a]);
	return (rem == 1);
}
int main()
{
	int n = 2;
	n = inputN();

	const int max_size = 100;
	int fractions[max_size];
	for (int i = 1; i < max_size; ++i)
	{
		fractions[i] = 1;
	}
	
	std::cout << std::endl;
	printFraction(fractions, n);
	std::cout << "; ";
	fractions[n]++;

	int i = n - 1;
	int j = n;
	while (fractions[n] / n != 1)
	{
		if (fractions[i] / i == 1)
		{
			i = n - 1;
			j = n;
		}
		if (minFraction(fractions, i, i - 1) == i - 1)
		{
			--i;
		}
		int current = 1;
		bool breakFlag = false;
		while (i < j)
		{
			if (minFraction(fractions, i, j) == i)
			{
				--j;
			}
			else
			{
				current = j;
				breakFlag = true;
				break;
			}
		}
		if (!breakFlag)
		{
			current = i;
			j = n;
		}
		if (isIrredFraction(fractions, current))
		{
			printFraction(fractions, current);
			std::cout << "; ";
			fractions[current]++;
		}
		else
		{
			fractions[current]++;
		}
	}

	int c = 0;
	std::cout << std::endl;
	std::cin >> c;
	std::cout << std::endl;
	return 0;
}

