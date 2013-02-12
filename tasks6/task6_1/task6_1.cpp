#include <iostream>

#include <iostream>
#include "set.h"

using std::cout;
using std::cin;
using std::endl;

namespace Commands
{
	enum Commands
	{
		exit,
		add,
		remove,
		exists,
		print,
		commandsList
	};
}
void printCommandList(std::ostream &out)
{
	out << "Command list:" << endl;
	out << Commands::exit << " - exit;" << endl;
	out << Commands::add << " - add element to set;" << endl;
	out << Commands::remove << " - remove element from set;" << endl;
	out << Commands::exists << " - does element belong to set;" << endl;
	out << Commands::print << " - print elements of set;" << endl;
	out << Commands::commandsList << " - help (print command list)";
	return;
}
int acceptValue(std::istream &in)
{
	if (!in.eof())
	{
		int result;
		in >> result;
		return result;
	}
	else 
	{
		return Commands::exit;
	}
}
void handleCommand(int command, Set *&set, std::istream &in, std::ostream &out)
{
	int elem = 0;
	switch (command)
	{
	case Commands::exit:
		out << "Exit ...";
		clearSet(set);
		delete set;
		return;
		break;
	case Commands::add:
		out << "Add. Enter added element: ";
		elem = acceptValue(in);
		out << endl;
		addElement(set, elem);
		if (elementExists(set, elem))
		{
			out << "New element (" << elem << ") was added successfully";
		}
		break;
	case Commands::remove:
		out << "Remove. Enter removed element: ";
		elem = acceptValue(in);
		out << endl;
		removeElement(set, elem);
		if (!elementExists(set, elem))
		{
			out << "Element (" << elem << ") was removed successfully";
		}
		break;
	case Commands::exists:
		out << "Exists. Enter element: ";
		elem = acceptValue(in);
		out << endl;
		if (elementExists(set, elem))
		{
			out << "Element (" << elem << ") belongs to the set";
		}
		else
		{
			out << "Element (" << elem << ") doesn't belong to the set";
		}
		break;
	case Commands::print:
		out << "Print. Choose order (1 - ascending; 0 - decreasing): ";
		out << endl;
		printSetElements(set, out, acceptValue(in));
		break;
	case Commands::commandsList:
		printCommandList(out);
		break;
	}
	out << endl;
}
int main()
{
	Set *set = createSet();
	cout <<  "The program of set control greetings you!" << std::endl;
	int command = Commands::commandsList;
	handleCommand(command, set, cin, cout);
	do
	{
		command = acceptValue(cin);
		handleCommand(command, set, cin, cout);
	} while (command != Commands::exit);

	cout << endl;
	return 0;
}