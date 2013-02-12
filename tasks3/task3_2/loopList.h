#pragma once

#include "listElement.h"

struct LoopList
{
	ListElement *pointer;
	int size;
};

LoopList* createLoopList(void);
void addElement(LoopList *list, int value);
void deleteElement(LoopList *list);
void clearList(LoopList *list);
int getSize(LoopList *list);
int getValue(LoopList *list);
void next(LoopList *list);
bool isEmpty(LoopList * list);
LoopList* copyLoopList(LoopList *list);