#pragma once

#include <iostream>
#include <fstream>

struct Node 
{
	int value;
	bool isOperator;
	Node *leftChild;
	Node *rightChild;
};
namespace Notations
{
	enum Notations
	{
		prefix,
		infix,
		postfix
	};
}
struct ParseTree
{
	Node *root;
};

ParseTree* createTree();
void parseExpression(ParseTree *tree, std::istream &in);
void printExpression(ParseTree *tree, std::ostream &out, int notation);
double calculate(ParseTree *tree);
void clearTree(ParseTree *tree);

//void test1();
