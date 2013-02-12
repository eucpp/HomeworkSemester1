#include <iostream>

int inputN()
{
	int n = 1;
	std::cout << "Enter N (N >= 1): ";
	std::cin >> n;
	if (n < 1)
	{
		std::cout << std::endl << "Incorrect N. Please, enter correct N >= 1" << std::endl;
		n = inputN();
		return n;
	}
	return n;
}
int recursiveFibonacci(int n)
{
	if ((n == 1) || (n == 2))
	{
		return 1;
	}
	else
	{
		return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
	}
}
void iterativeFibonacci(int n)
{
	int prev = 1;
	int prev2 = 0;
	std::cout << "1, ";
	--n;
	while (n > 0)
	{
		int current = prev + prev2;
		std::cout << current << ", ";
		prev2 = prev;
		prev = current;
		--n;
	}
}	
int main()
{
	const int n = 15;

	std::cout << "Fibonacci numbers by recursion: " << std::endl;
	for (int i = 1; i <= n; ++i)
	{
		std::cout << recursiveFibonacci(i) << ", ";
	}
	std::cout << std::endl;

	std::cout << "Fibonacci numbers by iteration: " << std::endl;
	iterativeFibonacci(n);
	std::cout << std::endl;

	int c = 0;
	std::cin >> c;
	std::cout << std::endl;
	return 0;
}

