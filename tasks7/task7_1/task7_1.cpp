#include <iostream>
#include <ios>
#include <fstream>
#include <string.h>
#include "hashTable.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	const int FNameSize = 30;
	char filename[FNameSize];
	cout << "Enter filename with text" << endl;
	cin >> filename;
	cout << endl;

	std::ifstream in;
	in.open(filename);
	std::ofstream out;
	out.open("output.txt");
	if (in.is_open())
	{
		in.seekg (0, std::ios::end);
		int startHTSize = in.tellg() * 0.1;
		in.seekg (0, std::ios::beg);
		HashTable *hashTable = createHashTable(startHTSize);
		time_t start = time(0);
		const int buffSize = 200;
		while (!in.eof())
		{
			char buffer[buffSize] = {'\0'};
			int i = 0;
			char ch = in.get();
			int code = getCode(ch);
			if (code == 36)
			{
				continue;
			}
			while (!in.eof() && code != 36)
			{
				buffer[i] = ch;
				i++;
				ch = in.get();
				code = getCode(ch);
			}
			addValue(hashTable, buffer);
		}
		printHashTable(hashTable, out);
		clearHashTable(hashTable);
		delete hashTable;
		time_t end = time(0);
		out << "Time of work: " << end - start << " s" << endl;
		
		cout << "Complete. Check output.txt" << endl;
		in.close();
	}
	else
	{
		cout << "Do not such file or directory!" << endl;
	}
	out.close();
	
	int nothing;
	cin >> nothing;
	cout << endl;
	return 0;
}