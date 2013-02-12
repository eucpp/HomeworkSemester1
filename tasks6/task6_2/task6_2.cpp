#include <iostream>
#include <fstream>
#include "parseTree.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	const int filenameSize = 200;
	char filename[filenameSize];
	cout << "Enter name of file which include parse tree: ";
	cin >> filename;
	cout << endl;

	std::ifstream inFile;
	inFile.open(filename);
	if (inFile.is_open())
	{
		ParseTree *tree = createTree();
		parseExpression(tree, inFile);
		cout << "Expresion: ";
		printExpression(tree, cout, Notations::prefix);
		cout << "Result = ";
		cout << calculate(tree);
		cout << endl;
		clearTree(tree);
		delete tree;
		inFile.close();
	}
	else
	{
		cout << "Not such file or directory!" << endl;
	}

	int nothing = 0;
	cin >> nothing;
	cout << endl;
	return 0;
}

