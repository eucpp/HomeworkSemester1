#include <iostream>

int main()
{
	const int str_size = 29;
	char str[str_size] = "";
	
	std::cout << "Enter string with length <= " << str_size + 1 << ": " << std::endl;
	std::cin.getline(str, str_size);
	std::cout << std::endl;
	
	int c = 0;
	int i = 0;
	while ((c >= 0) && (str[i] != '\0')) 
	{
		if (str[i] == '(') 
		{
			c++;
		}
		else if (str[i] == ')') 
		{
			c--;
		}
		++i;
	}
	if (c == 0) 
	{
		std::cout << "Balance of brackets is correct" << std::endl;
	}
	else 
	{
		std::cout << "Balance of brackets isn't correct" << std::endl;
	}
	
	std::cin >>	i;
	return 0;
}
