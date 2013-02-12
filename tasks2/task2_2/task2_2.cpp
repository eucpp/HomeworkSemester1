#include <iostream>

long int raisingTo(int a, int n)
{
	if (n == 1)
	{
		return a;
	}
	int degree = n / 2;
	long int temp = raisingTo(a, degree);
	long int sqr = temp * temp;
	if (n % 2 == 0)
	{
		return sqr;
	}
	else
	{
		return sqr * a;
	}
}
int main()
{
	int a;
	int n;
	std::cout << "Enter \"a\": ";
	std::cin >> a;
	std::cout << std::endl << "Enter \"n\": ";
	std::cin >> n;
	std::cout << std::endl;

	long int result = raisingTo(a, n);
	std::cout << "a^n = " << result;
	
	std::cout << std::endl;
	std::cin >>	a;
	std::cout << std::endl;
	return 0;
}

