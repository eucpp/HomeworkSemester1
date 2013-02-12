#include <stdlib.h>
#include <iostream>

#include "sortedList.h"

void testAddDelete()
{
	SortedList *test = createSortedList();
	printList(test);
	addElement(test, 5);
	addElement(test, 8);
	addElement(test, 1);
	addElement(test, 11);
	printList(test);
	deleteElement(test, 5);
	printList(test);
	deleteElement(test, 1);
	deleteElement(test, 2);
	printList(test);
	clearList(test);
	delete test;
	return;
}
void hello()
{
	std::cout << "The program of sorted list control greetings you!" << std::endl;
}
void goodbye()
{
	std::cout << std::endl << "Exit ..." << std::endl;
}
void commandsList()
{
	std::cout << std::endl << "Commands list:" << std::endl;
	std::cout << "0 - exit" << std::endl;
	std::cout << "1 - add value to sorted list" << std::endl;
	std::cout << "2 - remove value from list" << std::endl;
	std::cout << "3 - print list" << std::endl;
}
int inputCommand()
{
	int command = 0;
	std::cin >> command;
	if ((command < 0) || (command > 3))
	{
		std::cout << "Incorrect command!" << std::endl;
		command = inputCommand();
	}
	return command;
}
void acceptCommand(SortedList *&list)
{
	commandsList();
	int command = inputCommand();
	switch (command)
	{
		case 0:
		{
			goodbye();
			clearList(list);
			delete list;
			exit(EXIT_SUCCESS);
			break;
		}
		case 1:
		{
			std::cout << "Add. Enter value:";
			int value = 0;
			std::cin >> value;
			addElement(list, value);
			break;
		}
		case 2:
		{
			std::cout << "Remove. Enter value:";
			int value = 0;
			std::cin >> value;
			deleteElement(list, value);
			break;
		}
		case 3:
		{
			printList(list);
			break;
		}
	}
	acceptCommand(list);
}
int main()
{
	//testAddDelete();

	hello();
	SortedList *list = createSortedList();
	acceptCommand(list);
}

