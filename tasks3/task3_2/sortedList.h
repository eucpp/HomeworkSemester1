#pragma once

#include "listElement.h"

struct SortedList
{
	ListElement *head;
	int size;
};

SortedList* createSortedList();
void addElement(SortedList *list, int value);
void deleteElement(SortedList *list, int offset);
void clearList(SortedList *list);
int getSize(SortedList *list);
void printList(SortedList *list);
int getFirst(SortedList *list);
SortedList* getPointer(SortedList *list, int value);