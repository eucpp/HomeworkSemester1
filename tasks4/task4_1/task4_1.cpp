#include <iostream>

bool strFromStr(char str1[], char str2[], int length1, int length2)
{
	if (length1 < length2)
	{
		return false;
	}
	
	const int charsCount = 256;
	int chars[charsCount];
	for (int i = 0; i < charsCount; i++)
	{
		chars[i] = 0;
	}

	for (int i = 0; i < length2; i++)
	{
		chars[str1[i]]--;
		chars[str2[i]]++;
	}
	for (int i = length2; i < length1; i++)
	{
		chars[str1[i]]--;
	}
	for (int i = 0; i < charsCount; i++)
	{
		if (chars[i] > 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	const int maxSize = 40;
	char str1[maxSize] = "";
	char str2[maxSize] = "";

	std::cout << "Enter first string (with length no more than 40 chars): " << std::endl;
	std::cin.getline(str1, maxSize);
	std::cout << std::endl << "Enter second string (with length no more than 40 chars): " << std::endl;
	std::cin.getline(str2, maxSize);
	std::cout << std::endl;

	int length1 = strlen(str1);
	int length2 = strlen(str2);

	int result = strFromStr(str1, str2, length1, length2);

	if (result)
	{
		std::cout << "The second string can be obtained from the chars of first string" << std::endl;
	}
	else
	{
		std::cout << "It is impossible to obtain the second string from the chars of first string" << std::endl;
	}

	int n;
	std::cin >> n;
	std::cout << std::endl;

	return 0; 
}

	

