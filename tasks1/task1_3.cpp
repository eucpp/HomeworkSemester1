#include <iostream>
#include <time.h>

void inverse(int array[], int start, int end) 
{
	int i = start, j = end;
	while (j > i) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		++i;
		--j;
	}
}
int main()
{
	int const array_size = 20;
	int array[array_size];
	
	std::cout << "Before inverting:" << std::endl;
	
	std::srand(time(0));
	for (int i = 0; i < array_size; i++) {
		array[i] = std::rand() % 10;
		std::cout << array[i] << " | ";
	}
	std::cout << std::endl;
	
	int m = 0;
	std::cout << "Enter m (0 <= m <= " << array_size - 1 << "): ";
	std::cin >> m;
	
	inverse(array, 0, m);
	inverse(array, m+1, array_size - 1);
	inverse(array, 0, array_size - 1);
	
	std::cout << std::endl << "After inverting:" << std::endl; 
	for (int i = 0; i < array_size; i++) {
		std::cout << array[i] << " | ";
	}
	
	std::cin >>	m;
	return 0;
}
