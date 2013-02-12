#pragma once

#include <iostream>
// #include <stdlib.h>
// #include <time.h>

struct Node 
{
	int value;
	Node *leftChild;
	Node *rightChild;
};
struct BinarySearchTree
{
	Node *root;
};

BinarySearchTree* createTree();
void addNode(BinarySearchTree *tree, int value);
void removeNode(BinarySearchTree *tree, int value);
bool nodeExists(BinarySearchTree *tree, int value);
Node* getNode(Node *root, int value);
bool isLeaf(Node *node);
void printTreeElements(BinarySearchTree *tree, std::ostream &out, bool ascendingOrder);
void clearTree(BinarySearchTree *tree);

/*
void test1();
void test2();
*/