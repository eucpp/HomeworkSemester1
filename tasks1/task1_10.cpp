#include <iostream>

int main()
{
	const int str_size = 29;
	char str[str_size] = "";

	std::cout << "Enter string with length <= " << str_size + 1 << ": " << std::endl;
	std::cin.getline(str, str_size);
	std::cout << std::endl;
	
	int i = 0, j = 0;
	j = strlen(str) - 1;
	
	bool b = true;
	while (j > i) 
	{
		if (str[i] != str[j]) 
		{
			b = false;
			break;
		}
		++i;
		--j;
	}
	if (b)
	{
		std::cout << "String  is a palindrome" << std::endl;
	}
	else 
	{
		std::cout << "String  isn't a palindrome " << std::endl;
	}
	
	
	std::cin >>	i;
	return 0;
}