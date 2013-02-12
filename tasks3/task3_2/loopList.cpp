#include <stdlib.h>
#include "loopList.h"

LoopList* createLoopList()
{
	LoopList *result = new LoopList;
	result->pointer = NULL;
	result->size = 0;
	return result;
}
int getSize(LoopList *list)
{
	return list->size;
}
bool isEmpty(LoopList *list)
{
	return (getSize(list) == 0);
}
void addElement(LoopList *list, int value)
{
	ListElement *newElement = new ListElement;
	newElement->value = value;
	if (list->pointer == NULL)
	{
		newElement->next = newElement;
		list->pointer = newElement;
	}
	else
	{
		ListElement *tmp = list->pointer->next;
		list->pointer->next = newElement;
		newElement->next = tmp;
		list->pointer = list->pointer->next;
	}
	list->size++;
}
// удаляет элемент, следующий за текущим указателем циклического списка
void deleteElement(LoopList *list)
{
	if (list->pointer == NULL)
	{
		return;
	}
	if (getSize(list) == 1)
	{
		delete list->pointer;
		list->pointer = NULL;
		list->size--;
		return;
	}
	ListElement *tmp = list->pointer->next;
	list->pointer->next = tmp->next;
	delete tmp;
	list->size--;
}
void clearList(LoopList *list)
{
	while (!isEmpty(list))
	{
		deleteElement(list);
	}
}
int getValue(LoopList *list)
{
	if (list->pointer == NULL)
	{
		return -1;
	}
	else
	{
		return list->pointer->value;
	}
}
void next(LoopList *list)
{
	list->pointer = list->pointer->next;
}
LoopList* copyLoopList(LoopList *list)
{
	LoopList *copy = createLoopList();
	if (getSize(list) == 0)
	{
		return copy;
	}
	ListElement *startPointer = list->pointer;
	do
	{
		addElement(copy, getValue(list));
		next(list);
	} while (list->pointer != startPointer);
	// передвигаем указатель на "первый" элемент (чтобы указатели оригинала и копии совпадали)
	next(copy);
	return copy;
}
