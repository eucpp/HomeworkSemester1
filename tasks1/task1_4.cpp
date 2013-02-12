#include <iostream>

int main()
{
	const int c = 28;
	int array[c];
	for (int i = 0; i < c; ++i) 
	{
		array[i] = 0;
	}
	for (int i = 0; i <= 9; ++i) 
	{
		for (int j = 0; j <= 9; ++j) 
		{
			for (int k = 0; k <= 9; ++k) 
			{
				array[i + j + k]++;
			}
		}
	}
	unsigned int s = 0;
	for (int i = 0; i < c; ++i) 
	{
		s += array[i] * array[i];
	}
	std::cout << "Amout of lucky tickets is " << s << std::endl; 
	
	std::cin >>	s;
	return 0;
}
