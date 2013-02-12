#include "list.h"

using std::cout;
using std::cin;
using std::endl;



List* createList()
{
	List *newList = new List;
	newList->head = nullptr;
	newList->current = nullptr;
	newList->size = 0;
	return newList;
}
ListElement *createListElement(char value)
{
	ListElement *newElement = new ListElement;
	newElement->value = value;
	newElement->next = nullptr;
	newElement->prev = nullptr;
	return newElement;
}

int getListSize(List *list)
{
	if (list == nullptr)
	{
		return 0;
	}
	return list->size;
}

void addElement(List *list, char value)
{
	if (list == nullptr)
	{
		return;
	}
	ListElement *newElement = createListElement(value);
	if (list->head != nullptr)
	{
		list->head->prev = newElement;
	}
	newElement->next = list->head;
	list->head = newElement;
	list->size++;
}
void printList(List *list, std::ostream &out)
{
	if (list == nullptr || list->head == nullptr)
	{
		return;
	}
	ListElement *current = list->head;
	while (current != nullptr)
	{
		out << current->value;
		current = current->next;
	}
}
bool isEmpty(List *list)
{
	return (list == nullptr || list->size == 0);
}
void clearList(List *&list)
{
	if (list == nullptr)
	{
		return;
	}
	while (list->head != nullptr)
	{
		ListElement *tmp = list->head;
		list->head = list->head->next;
		delete tmp;
	}
	delete list;
	list = nullptr;
}
bool exists(List *list, char value)
{
	if (list == nullptr)
		return false;
	ListElement *current = list->head;
	while (current != nullptr)
	{
		if (value == current->value)
			return true;
		current = current->next;
	}
	return false;
}

char first(List* list)
{
	list->current = list->head->next;
	return list->head->value;
}
char next(List* list)
{
	if (list->current == nullptr)
	{
		return '\0';
	}
	list->current = list->current->next;
	return list->current->prev->value;
}