#include "parseTree.h"

using std::cout;
using std::cin;
using std::endl;

ParseTree* createTree()
{
	ParseTree *tree = new ParseTree;
	tree->root = NULL;
	return tree;
}
Node* createNode(int value, bool isOperator)
{
	Node *node = new Node;
	node->value = value;
	node->isOperator = isOperator;
	node->leftChild = NULL;
	node->rightChild = NULL;
	return node;
}
bool isNumber(char ch)
{
	return  (ch >= '0') && (ch <= '9');
}
bool isOperator(char ch)
{
	return  (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');
}
void parseExpression(Node *&node, std::istream &in)
{
	char ch = in.get();
	while (!isNumber(ch) && !isOperator(ch) && !in.eof())
	{
		ch = in.get();
	}
	if (in.eof())
	{
		node = createNode('?', true);
		return;
	}
	else
	{
		bool isOperatorCh = isOperator(ch);
		int added = 0;
		if (isOperatorCh)
		{
			added = static_cast<int>(ch);
		}
		else
		{
			in.putback(ch);
			in >> added;
		}
		node = createNode(added, isOperatorCh);
		if (isOperatorCh)
		{
			parseExpression(node->leftChild, in);
			parseExpression(node->rightChild, in);
		}
	}
}
void parseExpression(ParseTree *tree, std::istream &in)
{
	parseExpression(tree->root, in);
}
void printValue(Node *node, std::ostream &out)
{
	if (node->isOperator)
	{
		out << static_cast<char>(node->value);
	}
	else
	{
		out << " " <<  node->value << " ";
	}
}
void printExpression(Node *node, std::ostream &out, int notation)
{
	if (node == NULL)
	{
		return;
	}
	if (notation == Notations::prefix)
	{
		printValue(node, out);
		printExpression(node->leftChild, out, notation);
		printExpression(node->rightChild, out, notation);
	}
	else if (notation == Notations::postfix)
	{
		printExpression(node->leftChild, out, notation);
		printExpression(node->rightChild, out, notation);
		printValue(node, out);
	}
	else
	{
		out << '(';
		printExpression(node->leftChild, out, notation);
		printValue(node, out);
		printExpression(node->rightChild, out, notation);
		out << ')';
	}
}
void printExpression(ParseTree *tree, std::ostream &out, int notation)
{
	printExpression(tree->root, out, notation);
	out << endl;
}
double calculate(Node *node)
{
	if (node->isOperator)
	{
		if (node->value == '?')
		{
			return 0;
		}
		double operand1 = calculate(node->leftChild);
		double operand2 = calculate(node->rightChild);
		char operat = static_cast<char>(node->value);
		switch (operat)
		{
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		case '/':
			return operand1 / operand2;
		}
	}
	else
	{
		return node->value;
	}
}
double calculate(ParseTree *tree)
{
	return calculate(tree->root);
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
void clearTree(ParseTree *tree)
{
	clearTree(tree->root);
	tree->root = NULL;
}

/*
void test1()
{
	ParseTree *tree = createTree();

	cout << "Create & print & calculate tree test" << endl << "Enter expression" << endl;
	parseExpression(tree, cin);
	char ch = ' ';
	while (ch != '\n')
	{
		cin.get(ch);
	}

	cout << endl;
	printExpression(tree, cout, Notations::prefix);
	cout << endl;
	printExpression(tree, cout, Notations::infix);
	cout << endl;
	printExpression(tree, cout, Notations::postfix);
	cout << endl;

	cout << calculate(tree) << endl;

	clearTree(tree);
	delete tree;
}
*/