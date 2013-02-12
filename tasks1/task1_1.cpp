#include <iostream>

int main()
{
	int x = 0;
	std::cout << "Enter x ";
	std::cin >> x;
	int sqr = 0;
	sqr = x * x;
	x = (sqr + x) * (sqr + 1 ) + 1;
	std::cout << "x^4 + x^3 + x^2 + x + 1 = " << x << std::endl;
	
	std::cin >> x;
	
	return 0;
}