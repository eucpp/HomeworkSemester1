#include "machine.h"

using std::cout;
using std::cin;
using std::endl;

Machine::Machine(char* filename) throw(int)
{
	try
	{
		std::ifstream in;
		in.open(filename);
		if (!in.is_open())
			throw 0;
		statesCount = 0;
		in >> statesCount;
		alphSize = 0;
		in >> alphSize;

		reset();

		transTable = new int*[statesCount];
		for (int i = 0; i < statesCount; i++)
			transTable[i] = new int[alphSize + 1];
		alphabet = new List*[alphSize];

		char ch = in.get();
		while (ch != '\n')
			ch = in.get();
		ch = in.get();
		int counter = 0;
	
		while (ch != '\n')
		{
			if (counter >= alphSize)
			{
				in.close();
				throw 1;
			}
			alphabet[counter] = createList();
			while (ch != '\n')
			{
				if (ch != ' ')
				{
					if (ch == '_')
						ch = ' ';
					addElement(alphabet[counter], ch);
					ch = in.get();
				}
				else
				{
					++counter;
					ch = in.get();
					break;
				}
			}
		}
		if (counter != alphSize - 1)
		{
			in.close();
			throw 2;
		}

		for (int i = 0; i < statesCount && !in.eof(); i++)
		{
			for (int j = 0; j <= alphSize; j++)
			{
				int trans = 0;
				in >> trans;
				transTable[i][j] = trans;
			}
			if (in.eof())
				break;
			char space = in.get();
			while (space != '\n' && !in.eof())
				space = in.get();
		}
		if (in.eof())
		{
			in.close();
			throw 3;
		}

		in >> succState;
		in >> errState;
		if ((succState < 0 || succState >= statesCount) || (errState < 0 || errState >= statesCount))
		{
			in.close();
			throw 4;
		}

		in.close();
	}
	catch (int e)
	{
		if (e > 0)
			clear();
		throw;
	}
}

Machine::~Machine()
{
	clear();
}

void Machine::move(char ch)
{
	if (state == succState || state == errState)
		return;

	word[ptr] = ch;
	ptr++;
	int chInd = alphSize;
	for (int i = 0; i < alphSize; ++i)
	{
		if (exists(alphabet[i], ch))
			chInd = i;
	}
	state = transTable[state][chInd];
}

bool Machine::endOfWord()
{
	return (state == succState || state == errState);
}
bool Machine::isCorrect()
{
	return (state == succState);
}
char* Machine::getWord()
{
	char* resultWord = new char[strlen(word)];
	strcpy(resultWord, word);
	return resultWord;
}
void Machine::reset()
{
	state = 0;
	ptr = 0;
	for (int i = 0; i < buffSize; i++)
		word[i] = '\0';
}

void Machine::clear()
{
	for (int i = 0; i < statesCount; ++i)
		delete[] transTable[i];
	delete[] transTable;
	for (int i = 0; i < alphSize; ++i)
		clearList(alphabet[i]);
	delete[] alphabet;
}

/*
void Machine::test()
{
	cout << "State transition table:" << endl;
	for (int i = 0; i < this->statesCount; i++)
	{
		for (int j = 0; j <= this->alphSize; j++)
			cout << this->transTable[i][j] << " ";
		cout << endl;
	}

	cout << "Alphabet:" << endl;
	for (int j = 0; j < this->alphSize; j++)
	{
		printList(this->alphabet[j], cout);
		cout << endl;
	}
}
*/