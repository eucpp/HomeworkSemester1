#include "string.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void setToZero(bool array[], int arraySize)
{
	for (int i = 0; i < arraySize; ++i)
	{
		array[i] = false;
	}
}
int main()
{
	const int alphabetSize = 256;
	bool usedChars[alphabetSize];
	setToZero(usedChars, alphabetSize);

	cout << "Enter text: " << endl;
	char current = cin.get();
	while (current != '\n')
	{
		char ch = current;
		current = cin.get();
		if (ch != ' ')
		{
			if (usedChars[ch])
			{
				continue;
			}
			else
			{
				cout << ch;
				usedChars[ch] = true;
			}
		}
		else
		{
			cout << endl;
			setToZero(usedChars, alphabetSize);
		}
	}

	int nothing;
	cout << endl;
	cin >> nothing;
	cout << endl;
	return 0;
}
