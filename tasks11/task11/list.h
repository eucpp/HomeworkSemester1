#pragma once

#include <iostream>
#include <string.h>

struct ListElement
{
	char value;
	ListElement *next;
	ListElement *prev;
};
struct List
{
	ListElement *head;
	ListElement *current;
	int size;
};

List* createList();
void addElement(List *list, char value);
bool isEmpty(List *list);
int getListSize(List *list);
void printList(List *list, std::ostream &out);
void clearList(List *&list);
bool exists(List *list, char value);
char first(List* list);
char next(List* list);