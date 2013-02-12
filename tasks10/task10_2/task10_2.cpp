#include <iostream>
#include <fstream>
#include <string.h>
#include "machine.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	try
	{
		const int strSize = 200;
		char fraction[strSize] = {'\0'};

		cout << "Enter fraction:" << endl;
		cin.getline(fraction, strSize - 1);
		cout << endl;
		int len = strlen(fraction);
		fraction[len] = ' ';

		Machine machine("fraction.txt");
		int i = 0;
		while (!machine.endOfWord() && i <= len)
		{
			machine.move(fraction[i]);
			i++;
		}
		if (machine.isCorrect())
			cout << "Correct fraction!";
		else
			cout << "Incorrect fraction!";
		cout << endl;
	}
	catch (int e)
	{
		cout << "Program error, sorry" << endl;
	}
	
	int nothing;
	cin >> nothing;
	cout << endl;
	return 0;
}