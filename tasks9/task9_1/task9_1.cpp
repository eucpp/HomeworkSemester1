#include <iostream>
#include <fstream>
#include "string.h"
#include "hashTable.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	const int maxSize = 40;
	char filename[maxSize] = {'\0'};

	std::ifstream first;
	cout << "Enter name of first file: ";
	cin >> filename;
	cout << endl;
	first.open(filename);

	std::ifstream second;
	cout << "Enter name of second file: ";
	cin >> filename;
	cout << endl;
	second.open(filename);

	std::ofstream third;
	cout << "Enter name of third file: ";
	cin >> filename;
	cout << endl;
	third.open(filename);

	if (!first.is_open() || !second.is_open() || !third.is_open())
	{
		cout << "Error. Cannot open files!" << endl;
	}
	else
	{
		const int bufferSize = 300;

		first.seekg (0, std::ios::end);
		int startHTSize = first.tellg() / bufferSize;
		first.seekg (0, std::ios::beg);
		HashTable *table = createHashTable(startHTSize);

		while (!first.eof())
		{
			char buffer[bufferSize] = {'\0'};
			first.getline(buffer, bufferSize);
			addValue(table, buffer);
		}
		while (!second.eof())
		{
			char buffer[bufferSize] = {'\0'};
			second.getline(buffer, bufferSize);
			if (exists(table, buffer))
			{
				third.write(buffer, strlen(buffer));
				third << endl;
			}
		}
		clearHashTable(table);
		delete table;
		first.close();
		second.close();
		third.close();
		cout << "Complete. Check " << filename << endl;

	}


	int nothing;
	cin >> nothing;
	cout << endl;
	return 0;
}
