#include <iostream>

int main()
{
	const int str_size = 29;
	char str[str_size] = "";
	char substr[str_size] = "";
	
	std::cout << "Enter string with length <= " << str_size + 1 << ": " << std::endl;
	std::cin.getline(str, str_size);
	std::cout << std::endl << "Enter substring with length <= " << str_size + 1 << ": " << std::endl;
	std::cin.getline(substr, str_size);
	std::cout << std::endl;
	
	int entry = 0;
	int len = 0;
	len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == substr[0])
		{
			bool b = true;
			int subLen = 1;
			subLen = strlen(substr);
			for (int j = 1; j < subLen; ++j)
			{
				if (str[i + j] != substr[j])
				{
					b = false;
					break;
				}
			}
			if (b)
			{
				++entry;
			}
		}
	}
	
	if (entry == 0)
	{
		std::cout << "String doesn't contain substring" << std::endl;
	}
	else
	{
		std::cout << "String contain substring " << entry << "x" << std::endl;
	}
	
	std::cin >>	entry;
	return 0;
}
