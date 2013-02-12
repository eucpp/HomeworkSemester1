#pragma once

#include <iostream>
#include <string.h>

struct ListElement
{
	char *key;
	int value;
	ListElement *next;
	ListElement *prev;
};
struct List
{
	ListElement *head;
	int size;
};

List* createList();
void addElement(List *list, char *key);
void addElement(List *list, ListElement *element);
void deleteElement(List *list, char *key);
bool exists(List *list, char *key);
bool isEmpty(List *list);
int getListSize(List *list);
void printList(List *list, std::ostream &out);
void clearList(List *list);
void deleteListElement(ListElement *del);

//void listTest();
//void joinTest();
