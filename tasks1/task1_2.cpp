#include <iostream>

int main()
{
	int a = 0;
	int b = 0;
	std::cout << "Enter \"a\": ";
	std::cin >> a;
	std::cout << std::endl << "Enter \"b\": ";
	std::cin >> b;
	std::cout << std::endl;
	
	int absA = 0;
	int absB = 0;
	absA = abs(a);
	absB = abs(b);
	
	int sum = 0;
	int q = 0;
	
	do
	{
		sum += absB;
		++q;
	}
	while (sum <= absA);
	--q;
	if (!((a * b) >= 0))
	{
		q = 0 - q;
	}
	
	
	std::cout << "\"a\" div \"b\" = " << q << std::endl;
	
	std::cin >> a;
	
	return 0;
}