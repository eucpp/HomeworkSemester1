#include <iostream>
#include "stack.h"
#include "priorityTable.h"


bool isNumber(char sign)
{
	return (sign >= '0') && (sign <= '9');
}
int main()
{
	const int strSize = 50;
	char str[strSize];

	std::cout << "Enter string with infix operators (length <= 50):" << std::endl;
	std::cin.getline(str, strSize);
	std::cout << std::endl;

	Stack *stack = NULL;
	int balance = 0;
	int length = strlen(str);

	for (int i = 0; i < length; ++i)
	{
		if (isNumber(str[i]))
		{
			if (isNumber(str[i + 1]))
			{
				std::cout << '(';
				std::cout << str[i] << str[i + 1];
				i++;
				while (isNumber(str[i + 1]))
				{
					++i;
					std::cout << str[i];
				}
				std::cout << ')';
			}
			else
			{
				std::cout << str[i];
			}
		}
		else  if (str[i] == '(')
		{
			push(stack, str[i]);
			balance++;
		}
		else if (str[i] == ')')
		{
			balance--;
			if (balance != 0)
			{
				std::cout << std::endl << "Error. A balance of brackets was broken";
				return 1;
			}
			char sign = pop(stack); 
			while (sign != '(')
			{
				std::cout << sign;
				sign = pop(stack);
			}
		}
		else
		{
			int priority = getPriority(str[i]);
			if (priority == -1)
			{
				continue;
			}
			char sign = getValue(stack);
			while ((stack != NULL) && (sign != '(') && (priority < getPriority(sign)))
			{
				std::cout << pop(stack);
				sign = getValue(stack);
			}
			push(stack, str[i]);
		}
	}
	while (stack != NULL)
	{
		std::cout << pop(stack);
	}
	cleanStack(stack);

	int nothing;
	std::cout << std::endl;
	std::cin >> nothing;
	std::cout << std::endl;
	return 0;
}
