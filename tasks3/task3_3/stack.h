#include <stdlib.h>

struct Stack
{
	char value;
	Stack *next;
};

void push(Stack *&stack, char value);
char pop(Stack *&stack);
char getValue(Stack *stack);
void cleanStack(Stack *&stack);
bool isEmpty(Stack *stack);