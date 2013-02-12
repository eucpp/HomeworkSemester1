#include <iostream>
#include <string.h>
#include "machine.h"

using std::cout;
using std::cin;
using std::endl;


bool ENonterminal(char *str, int &ptr);
bool EdashNonterminal(char *str, int &ptr);
bool TNonterminal(char *str, int &ptr);
bool TdashNonterminal(char *str, int &ptr);
bool FNonterminal(char *str, int &ptr);

void skip(char *str, int &ptr)
{
	if (str[ptr] == ' ')
		ptr++;
}

// F -> (E) | id
bool FNonterminal(char *str, int &ptr)
{
	if (str[ptr] == '(')
	{
		++ptr;
		if (ENonterminal(str, ptr))
			if (str[ptr] == ')')
				return true;
	}
	else
	{
		
		try
		{
			Machine machine("fraction.txt");
			while (!machine.endOfWord() && str[ptr] != '\0')
			{
				machine.move(str[ptr]);
				ptr++;
			}
			--ptr;
			return machine.isCorrect();
		}
		catch (int e)
		{
			return false;
		}
		
	}
}
// T` -> *FT`| /FT` | e
bool TdashNonterminal(char *str, int &ptr)
{
	skip(str, ptr);
	if (str[ptr] == '*' || str[ptr] == '/')
	{
		++ptr;
		skip(str, ptr);
		if (FNonterminal(str, ptr))
			if (str[ptr] == ' ')
				return true;
			else
				return TdashNonterminal(str, ptr);
	}
	else
	{
		return true;
	}
}
// T -> FT`
bool TNonterminal(char *str, int &ptr)
{
	if (FNonterminal(str, ptr))
		if (TdashNonterminal(str, ptr))
			return true;
	return false;
}
// E` -> +TE`| -TE` | e
bool EdashNonterminal(char* str, int &ptr)
{
	skip(str, ptr);
	if (str[ptr] == '+' || str[ptr] == '-')
	{
		++ptr;
		skip(str, ptr);
		if (TNonterminal(str, ptr))
		{
			if (str[ptr] == ' ')
				return true;
			else
				return EdashNonterminal(str, ptr);
		}
	}
	else
	{
		return true;
	}
}
// E -> TE`
bool ENonterminal(char* str, int &ptr)
{
	if (TNonterminal(str, ptr))
		if (EdashNonterminal(str, ptr))
			return true;
}

bool isCorrectExp(char *str, int start)
{
	return ENonterminal(str, start);
}
int main()
{
	const int buffSize = 200;
	char buff[buffSize] = {'\0'};
	cout << "Enter expression" << endl;
	cout << "For example: 12 + 3 * ( 17 - 2 )" << endl;
	cin.getline(buff, buffSize);
	cout << endl;
	buff[strlen(buff)] = ' ';

	if (isCorrectExp(buff, 0))
		cout << "Correct expression!";
	else 
		cout << "Incorrect expression!";
	cout << endl;

	int nothing;
	cin >> nothing;
	cout << endl;
	return 0;
}