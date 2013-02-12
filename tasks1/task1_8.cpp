#include <iostream>

int recursionFactorial(int f)
{
	if (f == 1)
	{
		return 1;
	}
	else
	{
		int fact = recursionFactorial(f - 1);
		return fact * f;
	}
}
int iterativeFactorial(int f)
{
	int fact = 1;
	for (int i = 1; i <= f; ++i)
	{
		fact *= i;
	}
	return fact;
}
int main()
{
	int f = 1;
	std::cout << "Enter f (f >= 1): ";
	std::cin >> f;
	std::cout << std::endl;
	
	int fact = 0;
	fact = recursionFactorial(f);
	std::cout << "recursion factorial f = " << fact << std::endl;
	fact = iterativeFactorial(f);
	std::cout << "iterative factorial f = " << fact << std::endl;
	
	std::cin >>	f;
	return 0;
}