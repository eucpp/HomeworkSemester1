#include "hashTable.h"

using std::endl;

List** createListsTable(unsigned int size)
{
	List** table = new List*[size];
	for (int i = 0; i < size; i++)
	{
		table[i] = NULL;
	}
	return table;
}
HashTable* createHashTable(unsigned int size)
{
	HashTable *newTable = new HashTable;
	newTable->size = size;
	newTable->countElem = 0;
	newTable->collision = 0;
	newTable->hash = longSumHash;
	newTable->table = createListsTable(size);
	return newTable;
}
double getLoadFactor(HashTable *table)
{ 
	return static_cast<double>(table->countElem) / table->size;;
}
void restruct(HashTable *table)
{
	if (table->size > 0xFFFFFF9B)
	{
		return;
	}
	unsigned int maxIncrease = 0xFFFFFFFF - table->size;
	unsigned int increase = table->countElem;
	while (increase > maxIncrease)
	{
		increase /= 2;
	}
	unsigned int newSize = table->size + increase;
	List **newTable = createListsTable(newSize);
	unsigned int newCollision = 0;
	for (int i = 0; i < table->size; i++)
	{
		if (getListSize(table->table[i]) > 0)
		{
			ListElement *tmp = table->table[i]->head;
			while (tmp != NULL)
			{
				unsigned int ind = table->hash(tmp->key, newSize);
				if (newTable[ind] == NULL)
				{
					newTable[ind] = createList();
				}
				else if (!exists(table->table[ind], tmp->key))
				{
					newCollision++;
				}
				addElement(newTable[ind], tmp);
				tmp = tmp->next;
			}
		}
	}
	unsigned int countElem = table->countElem;
	clearHashTable(table);
	table->table = newTable;
	table->size = newSize;
	table->countElem = countElem;
	table->collision = newCollision;
}
void addValue(HashTable *table, char *value)
{
	unsigned int ind = table->hash(value, table->size);
	if (table->table[ind] == NULL)
	{
		table->table[ind] = createList();
	}
	else if (!exists(table->table[ind], value))
	{
		table->collision++;
	}
	addElement(table->table[ind], value);
	table->countElem++;
	if (getLoadFactor(table) > 0.9)
	{
		restruct(table);
	}
}
void deleteValue(HashTable *table, char *value)
{
	unsigned int ind = table->hash(value, table->size);
	deleteElement(table->table[ind], value);
	table->countElem--;
}
bool exists(HashTable *table, char *value)
{
	unsigned int ind = table->hash(value, table->size);
	return exists(table->table[ind], value);
}
void printHashTable(HashTable *table, std::ostream &out)
{
	out << "Hash table:" << endl;
	int maxList = 0;
	for (int i = 0; i < table->size; ++i)
	{
		int listSize = getListSize(table->table[i]);
		if (listSize > maxList)
		{
			maxList = listSize;
		}
		if (listSize != 0)
		{
			printList(table->table[i], out);
		}
	}
	out << "-----------------------------------------------------------------------" << endl;
	out << "Short statistics" << endl;
	out << "Size of table: " << table->size << endl;
	out << "Count of elements: " << table->countElem << endl;
	out << "Count of collision: " << table->collision << endl;
	out << "Percent of collision: " << (static_cast<double>(table->collision) / table->countElem) * 100 << "%" << endl;
	out << "Most loaded cell: " << maxList << endl; 
	out << "Load factor: " << getLoadFactor(table) << endl;
}
void clearHashTable(HashTable *table)
{
	for (int i = 0; i < table->size; ++i)
	{
		clearList(table->table[i]);
		if (table->table[i] != NULL)
		{
			delete table->table[i];
		}
	}
	delete[] table->table;
	table->table = NULL;
	table->size = 0;
	table->countElem = 0;
	table->collision = 0;
}

/*
void hashTableTest(unsigned int tableSize, unsigned int tests)
{
	std::cout << "Hash table test" << std::endl;
	
	HashTable *hashTable = createHashTable(tableSize);
	char *val = getRandomStr(true);
	addValue(hashTable, val);
	for (int i = 0; i < tests - 1; i++)
	{
		val = getRandomStr(false);
		addValue(hashTable, val);
	}
	printHashTable(hashTable, std::cout);
	clearHashTable(hashTable);
	delete hashTable;
}
*/