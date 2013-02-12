#include <iostream>

int main()
{
	int a;
	int n;
	std::cout << "Enter \"a\": ";
	std::cin >> a;
	std::cout << std::endl << "Enter \"n\": ";
	std::cin >> n;
	std::cout << std::endl;
	
	int result = 1;
	for (int i = 1; i <= n; ++i)
	{
		result *= a;
	}
	std::cout << "a^n = " << result;
	
	std::cin >>	a;
	return 0;
}