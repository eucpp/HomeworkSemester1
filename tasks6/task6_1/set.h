#pragma once

#include "binarySearchTree.h"

struct Set
{
	BinarySearchTree *tree;
};

Set* createSet();
void addElement(Set *set, int value);
void removeElement(Set *set, int value);
bool elementExists(Set *set, int value);
void printSetElements(Set *set, std::ostream &out, bool ascendingOrder);
void clearSet(Set *set);