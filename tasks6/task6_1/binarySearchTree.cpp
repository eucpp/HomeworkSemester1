#include "binarySearchTree.h"

using std::cout;
using std::cin;
using std::endl;

BinarySearchTree* createTree()
{
	BinarySearchTree *tree = new BinarySearchTree;
	tree->root = NULL;
	return tree;
}
Node* createNode(int value)
{
	Node *node = new Node;
	node->value = value;
	node->leftChild = NULL;
	node->rightChild = NULL;
	return node;
}
Node* getNode(Node *root, int value)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (value == root->value)
	{
		return root;
	}
	else if (value < root->value)
	{
		return getNode(root->leftChild, value);
	}
	else
	{
		return getNode(root->rightChild, value);
	}
}
Node* getLeftmostChild(Node *node)
{
	if (node == NULL)
	{
		return  NULL;
	}
	else if (node->leftChild == NULL)
	{
		return node;
	}
	else
	{
		return getLeftmostChild(node->leftChild);
	}
}
bool nodeExists(BinarySearchTree *tree, int value)
{
	Node *node = getNode(tree->root, value);
	return (node != NULL);
}
bool isLeaf(Node *node)
{
	return (node->leftChild == NULL && node->rightChild == NULL);
}
void addNode(Node *&node, int value)
{
	if (node == NULL)
	{
		node = createNode(value);
	}
	else if (value < node->value)
	{
		addNode(node->leftChild, value);
	}
	else if (value > node->value)
	{
		addNode(node->rightChild, value);
	}
	else
	{
		return;
	}
}
void addNode(BinarySearchTree *tree, int value)
{
	addNode(tree->root, value);
}
void removeNode(Node *&node, int value)
{
	if (node == NULL)
	{
		return;
	}
	else if (value < node->value)
	{
		removeNode(node->leftChild, value);
		return;
	}
	else if (value > node->value)
	{
		removeNode(node->rightChild, value);
		return;
	}
	else
	{
		if (isLeaf(node))
		{
			delete node;
			node = NULL;
		}
		else if (node->leftChild != NULL && node->rightChild == NULL)
		{
			Node *tmp = node;
			node = node->leftChild;
			delete tmp;
		}
		else if (node->leftChild == NULL && node->rightChild != NULL)
		{
			Node *tmp = node;
			node = node->rightChild;
			delete tmp;
		}
		else
		{
			Node *leftmost = getLeftmostChild(node);
			node->value = leftmost->value;
			removeNode(node->leftChild, leftmost->value);
		}
	}
}
void removeNode(BinarySearchTree *tree, int value)
{
	removeNode(tree->root, value);
}
void printTreeElements(Node *node, std::ostream &out, bool ascendingOrder)
{
	if (node == NULL)
	{
		return;
	}	
	Node *first = NULL;
	Node *second = NULL;
	if (ascendingOrder)
	{
		first = node->leftChild;
		second = node->rightChild;
	}
	else
	{
		first = node->rightChild;
		second = node->leftChild;
	}
	printTreeElements(first, out, ascendingOrder);
	out << node->value << " ";
	printTreeElements(second, out, ascendingOrder);
}
void printTreeElements(BinarySearchTree *tree, std::ostream &out, bool ascendingOrder)
{
	printTreeElements(tree->root, out, ascendingOrder);
}
void clearTree(Node *node)
{
	if (node == NULL)
	{
		return;
	}
	clearTree(node->leftChild);
	clearTree(node->rightChild);
	delete node;
}
void clearTree(BinarySearchTree *tree)
{
	clearTree(tree->root);
}

/*
void test1()
{
	cout << "Test 1 - add/remove/exists" << endl;
	BinarySearchTree *tree = createTree();
	addNode(tree, 0);
	cout << "Add element 0" << endl;
	addNode(tree, 2);
	cout << "Add element 2" << endl;
	addNode(tree, -5);
	cout << "Add element -5" << endl;
	addNode(tree, 1);
	cout << "Add element 1" << endl;
	cout << "0 exists = " << nodeExists(tree, 0) << endl;
	cout << "1 exists = " << nodeExists(tree, 1) << endl;
	cout << "7 exists = " << nodeExists(tree, 7) << endl;
	removeNode(tree, 2);
	cout << "Remove element 2" << endl;
	cout << "2 exists = " << nodeExists(tree, 2) << endl;
	cout << "1 exists = " << nodeExists(tree, 1) << endl;
}
void test2()
{
	cout << "Test 2 - print" << endl;
	BinarySearchTree *tree = createTree();
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int value = rand() % 100;
		addNode(tree, value);
		cout << "Add element " << value << endl;
	}
	cout << "Ascending order: " << endl;
	printTreeElements(tree, cout, true);
	cout << endl;
	cout << "Decreasing order: " << endl;
	printTreeElements(tree, cout, false);
	cout << endl;
}
*/