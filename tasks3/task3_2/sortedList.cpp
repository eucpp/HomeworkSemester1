#include <stdlib.h>
#include <iostream>
#include "sortedList.h"

SortedList* createSortedList()
{
	SortedList *newList = new SortedList;
	newList->head = NULL;
	newList->size = 0;
	return newList;
}
int getSize(SortedList *list)
{
	return list->size;
}
void addElement(SortedList *list, int value)
{
	ListElement *newElement = new ListElement;
	newElement->value = value;
	if ((list->head == NULL) || (newElement->value >= list->head->value))
	{
		newElement->next = list->head;
		list->head = newElement;
	}
	else
	{
		ListElement *pointer = list->head;
		while ((pointer->next != NULL) && (pointer->next->value >= newElement->value))
		{
			pointer = pointer->next;
		}
		newElement->next = pointer->next;
		pointer->next = newElement;
	}
	list->size++;
}
void deleteElement(SortedList *list, int value)
{
	if (list->head == NULL)
	{
		return;
	}
	else if (value == list->head->value)
	{
		ListElement *tmp = list->head;
		list->head = list->head->next;
		delete tmp;
		list->size--;
	}
	else
	{
		ListElement *pointer = list->head;
		while ((pointer->next != NULL) && (pointer->next->value != value))
		{
			pointer = pointer->next;
		}
		if (pointer->next == NULL)
		{
			return;
		}
		else
		{
			ListElement *tmp = pointer->next;
			pointer->next = pointer->next->next;
			delete tmp;
			list->size--;
		}
	}
}
void clearList(SortedList *list)
{
	while (list->head != NULL)
	{
		deleteElement(list, list->head->value);
	}
	list->size = 0;
}
void printList(SortedList *list)
{
	std::cout << "SortedList: ";
	ListElement *pointer = list->head;
	while (pointer != NULL)
	{
		std::cout << pointer->value << " --> ";
		pointer = pointer->next;
	}
	std::cout << "NULL" << std::endl;
}
int getFirst(SortedList *list)
{
	if ((list == NULL) ||(list->head == NULL))
	{
		return -1;
	}
	else
	{
		return list->head->value;
	}
}
SortedList* getPointer(SortedList *list, int value)
{
	SortedList *pointer = list;
	if (pointer == NULL)
	{
		return pointer;
	}
	else
	{
		while (pointer->head->value != value)
		{
			pointer->head = pointer->head->next;
			if (pointer == NULL)
			{
				break;
			}
		}
		return pointer;
	}
}
