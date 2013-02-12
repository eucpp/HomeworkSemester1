#include <stdlib.h>
#include <iostream>
#include "loopList.h"

void test()
{
	std::cout << "getSize, isEmpty, getValue and next test" << std::endl;
	LoopList *test = createLoopList();
	std::cout << "size = " << getSize(test) << " is empty? " << isEmpty(test) << std::endl;
	addElement(test, 7);
	addElement(test, 8);
	std::cout << "size = " << getSize(test) << " is empty? " << isEmpty(test) << std::endl;
	std::cout << getValue(test) << std::endl;
	next(test);
	std::cout << getValue(test) << std::endl;
	deleteElement(test);
	deleteElement(test);
	std::cout << "size = " << getSize(test) << " is empty? " << isEmpty(test) << std::endl;
}
void addTest()
{
	std::cout << "add test" << std::endl;
	LoopList *test = createLoopList();
	addElement(test, 7);
	addElement(test, 8);
	addElement(test, 9);
	addElement(test, 10);
	for (int i = 0; i < 4; i++)
	{
		std::cout << getValue(test) << " ---> ";
		next(test);
	}
	std::cout <<std::endl;
}
void deleteTest()
{
	std::cout << "delete test" << std::endl;
	LoopList *test = createLoopList();
	addElement(test, 100);
	addElement(test, 200);
	for (int i = 0; i < 2; i++)
	{
		std::cout << getValue(test) << " ---> ";
		next(test);
	}
	std::cout << std::endl;
	deleteElement(test);
	std::cout << getValue(test) << " ---> ";
	deleteElement(test);
	std::cout << getValue(test);
	std::cout << std::endl;
}
void copyTest()
{
	std::cout << "copy test" << std::endl;
	LoopList *test = createLoopList();
	addElement(test, 7);
	addElement(test, 8);
	addElement(test, 9);
	addElement(test, 10);
	LoopList *copy = copyLoopList(test);
	for (int i = 0; i < 4; i++)
	{
		std::cout << getValue(copy) << " ---> ";
		next(copy);
	}
	std::cout << std::endl;
}
int inputNum()
{
	int num = 1;
	std::cout << "Enter the number of elements of loop list:";
	std::cin >> num;
	std::cout << std::endl;
	if (num < 1)
	{
		std::cout << "Incorrect value." << std::endl;
		num = inputNum();
	}
	return num;
}
int inputLastEl(int num)
{
	int lastEl = 1;
	std::cout << "Enter the last element:";
	std::cin >> lastEl;
	std::cout << std::endl;
	if ((lastEl < 1) || (lastEl > num))
	{
		std::cout << "Incorrect value." << std::endl;
		lastEl = inputNum();
	}
	return lastEl;
}
int main()
{
	/*
	test();
	addTest();
	deleteTest();
	copyTest();
	*/

	int num = 1;
	num = inputNum();
	int lastEl = 1;
	lastEl = inputLastEl(num);

	LoopList *loopList = createLoopList();
	for (int i = 1; i <= num; ++i)
	{
		addElement(loopList, i);
	}
	// передвигаем указатель на "1" (первый элемент)
	next(loopList);
	int *results = new int[num + 1];

	LoopList *copy = NULL;
	for (int i = 1; i <= num; ++i)
	{
		copy = copyLoopList(loopList);
		while (getSize(loopList) != 1)
		{
			for (int j = 1; j < i; j++)
			{
				next(loopList);
			}
			deleteElement(loopList);
			next(loopList);
		}
		results[i] = getValue(loopList);
		clearList(loopList);
		loopList = copy;
	}
	clearList(loopList);
	clearList(copy);
	delete loopList;

	std::cout << lastEl << " is a last element when a step of deleting is: ";
	for (int i = 1; i <= num; ++i)
	{
		if (results[i] == lastEl)
		{
			std::cout << i << ", ";
		}
	}
	delete []results;

	std::cout << std::endl;
	std::cin >> num;
	std::cout << std::endl;
	return 0;
}