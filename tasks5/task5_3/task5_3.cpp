#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

bool compareChars(char *first, char *second, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (first[i] != second[i])
		{
			return false;
		}
	}
	return true;
}
void offsetStr(char str[], int pos, char ch)
{
	for (int i = 0; i < pos - 1; i++)
	{
		str[i] = str[i + 1];
	}
	str[pos - 1] = ch;
}
void skip(std::istream &in, char endSkip[])
{
	int length = strlen(endSkip);
	char *chars = new char[length];
	in.read(chars, length);
	while (!in.eof())
	{
		if (compareChars(chars, endSkip, length))
		{
			delete[] chars;
			return;
		}
		offsetStr(chars, length, in.get());
	}
	delete[] chars;
	return;
}
int main()
{
	const int maxFileNameSize = 30;
	char filename[maxFileNameSize] = "";
	cout << "Enter filename (not more than " << maxFileNameSize << " chars): ";
	cin >> filename;
	cout << endl;
	std::ifstream inFile;
	inFile.open(filename);

	if(inFile.is_open())
	{
		char buffer[2] = "";
		char current = ' ';
		while (!inFile.eof())
		{
			current = ' ';
			buffer[1] = buffer[0];
			inFile.get(buffer[0]);
			if ((buffer[1] == '/') && (buffer[0] == '/'))
			{
				cout << "//";
				while (!(inFile.eof()) && (current != '\n'))
				{
					cout << current;
					inFile.get(current);
				}
				cout << endl;
				buffer[0] = ' ';
				buffer[1] = ' ';
				if (inFile.eof())
				{
					break;
				}
			}
			else if ((buffer[1] == '/') && (buffer[0] == '*'))
			{
				char endComment[] = "*/";
				skip(inFile, endComment);
				buffer[0] = ' ';
				buffer[1] = ' ';
			}
			else if (buffer[0] == '"')
			{
				char endString[] = "\"";
				skip(inFile, endString);
				buffer[0] = ' ';
				buffer[1] = ' ';
			}
		}
		inFile.close();
	}
	else
	{
		cout << "Not such file or directory!" << endl;
	}
	int nothing = 0;
	cin >> nothing;
	return 0;
}