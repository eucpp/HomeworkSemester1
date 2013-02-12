#include "set.h"

Set* createSet()
{
	Set *set = new Set;
	BinarySearchTree *tree = createTree();
	set->tree = tree;
	return set;
}
void addElement(Set *set, int value)
{
	addNode(set->tree, value);
}
void removeElement(Set *set, int value)
{
	removeNode(set->tree, value);
}
bool elementExists(Set *set, int value)
{
	return nodeExists(set->tree, value);
}
void printSetElements(Set *set, std::ostream &out, bool ascendingOrder)
{
	printTreeElements(set->tree, out, ascendingOrder);
}
void clearSet(Set *set)
{
	clearTree(set->tree);
	delete set->tree;
}