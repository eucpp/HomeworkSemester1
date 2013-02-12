#include <iostream>
#include <string.h>
#include "polynomial.h"

using std::cout;
using std::cin;
using std::endl;

namespace Commands
{
	enum Commands
	{
		exit,
		add,
		equals,
		value,
		commandsList
	};
}
Polynomial* readPolynomial()
{
	const int buffSize = 200;
	char buffer[buffSize] = {'\0'};
	cin.getline(buffer, buffSize);
	int len = strlen(buffer);
	buffer[len] = ' ';
	Polynomial *p = createPolynomial(buffer);
	return p;
}
int polynomialConsole(Polynomial *&p, int command = 0)
{
	cout << "Polynomial: " << endl;
	printPolynomial(p, cout);
	if (command == 0)
	{
		cin >> command;
		cin.get();
	}
	int x = 0;
	Polynomial *q = nullptr;
	Polynomial *r = nullptr;
	switch (command)
	{
	case Commands::exit:
		cout << "Exit..." << endl;
		break;
	case Commands::add:
		cout << "Add. Enter added polynomial:" << endl;
		q = readPolynomial();
		r = add(p, q);
		clearPolynomial(p);
		clearPolynomial(q);
		p = r;
		break;
	case Commands::equals:
		cout << "Equals. Enter polynomial:" << endl;
		q = readPolynomial();
		if (equals(p, q))
			cout << "Polynomials are equivalent";
		else
			cout << "Polynomials aren't equivalent";
		clearPolynomial(q);
		break;
	case Commands::value:
		cout << "Value. Enter x: ";
		x = 0;
		cin >> x;
		cout << endl << "Result: " << value(p, x);
		break;
	case Commands::commandsList:
		cout << Commands::exit << " - Exit" << endl;
		cout << Commands::add << " - Add" << endl;
		cout << Commands::equals << " - Equals" << endl;
		cout << Commands::value << " - Value" << endl;
		cout << Commands::commandsList << " - Help (command list)" << endl;
		break;
	}
	cout << endl << endl;
	return command;
}
int main()
{
	cout << "Enter polynomial (For example: x^2 + 2x + 1):" << endl;
	Polynomial *p = readPolynomial();
	while (p == nullptr)
	{
		cout << "Incorrect polynomial" << endl;
		cout << "Enter polynomial:" << endl;
		clearPolynomial(p);
		p = readPolynomial();
	}
	cout << endl;

	
	int command = polynomialConsole(p, Commands::commandsList);
	while (command != 0)
		command = polynomialConsole(p);

	clearPolynomial(p);
}
