#include <iostream>

int main()
{
	unsigned int N = 0;
	std::cout << "Enter N (N > 2): ";
	std::cin >> N;
	std::cout << std::endl;
	
	std::cout << 2 << " | ";
	for (int i = 3; i <= N; ++i)
	{
		bool b = true;
		for (int j = 2; j < i - 1; ++j)
		{
			if ((i % j) == 0)
			{
				b = false;
				break;
			}
		}
		if (b)
		{
			std::cout << i << " | ";
		}
	}
	
	
	std::cin >>	N;
	return 0;
}
