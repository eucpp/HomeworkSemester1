#include "list.h"

using std::cout;
using std::cin;
using std::endl;



List* createList()
{
	List *newList = new List;
	newList->head = NULL;
	newList->size = 0;
	return newList;
}
ListElement *createListElement(char *key)
{
	ListElement *newElement = new ListElement;
	int len = strlen(key) + 1;
	newElement->key = new char[len];
	strcpy(newElement->key, key);
	newElement->value = 1;
	newElement->next = NULL;
	newElement->prev = NULL;
	return newElement;
}

int getListSize(List *list)
{
	if (list == NULL)
	{
		return 0;
	}
	return list->size;
}
ListElement* getElem(List *list, char *key)
{
	if (list == NULL || list->head == NULL)
	{
		return NULL;
	}
	ListElement* current = list->head;
	while (current != NULL && strcmp(current->key, key) != 0)
	{
		current = current->next;
	}
	return current;
}
void addElement(List *list, char *key)
{
	if (list == NULL)
	{
		return;
	}
	ListElement* elem = getElem(list, key);
	if (elem == NULL)
	{
		ListElement *newElement = createListElement(key);
		if (list->head != NULL)
		{
			list->head->prev = newElement;
		}
		newElement->next = list->head;
		list->head = newElement;
		list->size++;
	}
	else
	{
		elem->value++;
	}
}
void addElement(List *list, ListElement *element)
{
	if (list == NULL)
	{
		return;
	}
	ListElement* added = createListElement(element->key);
	added->value = element->value;
	if (list->head != NULL)
	{
		list->head->prev = added;
	}
	added->next = list->head;
	list->head = added;
	list->size++;
}
bool exists(List *list, char *key)
{
	return (getElem(list, key) != NULL);
}
void deleteListElement(ListElement *del)
{
	delete[] del->key;
	delete del;
}
void deleteElement(List *list, char *key)
{
	if (list == NULL || list->head == NULL)
	{
		return;
	}
	ListElement* elem = getElem(list, key);
	if (elem == list->head)
	{
		list->head = elem->next;
		if (list->head != NULL)
		{
			list->head->prev = NULL;
		}
	}
	else
	{
		ListElement *prev = elem->prev;
		ListElement *next = elem->next;	
		prev->next = next;
		if (next != NULL)
		{
			next->prev = prev;
		}
	}
	deleteListElement(elem);
	list->size--;
}

void printList(List *list, std::ostream &out)
{
	if (list == NULL)
	{
		return;
	}
	ListElement *current = list->head;
	while (current != NULL)
	{
		out << current->key << " - " << current->value << endl;
		current = current->next;
	}
}
bool isEmpty(List *list)
{
	return (list == NULL || list->size == 0);
}

void clearList(List *list)
{
	if (list == NULL || list->head == NULL)
	{
		return;
	}
	while (!isEmpty(list))
	{
		deleteElement(list, list->head->key);
	}
	list->head = NULL;
}

/*
void listTest()
{
	List *list = createList();
	addElement(list, "One");
	addElement(list, "Two");
	addElement(list, "Three");
	printList(list, cout);
	deleteElement(list, "Two");
	deleteElement(list, "Three");
	printList(list, cout);
	addElement(list, "fout");
	printList(list, cout);
	clearList(list);
	printList(list, cout);
	delete list;
}
*/