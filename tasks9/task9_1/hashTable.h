#pragma once

#include <iostream>
#include <time.h>
#include "list.h"
#include "hash.h"

struct HashTable
{
	List **table;
	unsigned int size;
	unsigned int countElem;
	unsigned int collision;
	unsigned int (*hash)(char*, unsigned int);
};

HashTable* createHashTable(unsigned int size);
void addValue(HashTable *table, char *value);
void deleteValue(HashTable *table, char *value);
bool exists(HashTable *table, char *value);
double getLoadFactor(HashTable *table);
void printHashTable(HashTable *table, std::ostream &out);
void clearHashTable(HashTable *table);


//void hashTableTest(unsigned int tableSize, unsigned int tests);