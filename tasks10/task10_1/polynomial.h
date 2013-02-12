#pragma once

#include <iostream>
#include <string.h>

struct Monomial
{
	int a;
	int n;
	Monomial *next;
	Monomial *prev;
};
struct Polynomial
{
	Monomial *head;
};

Polynomial* createPolynomial(char *str);
bool equals(Polynomial *p, Polynomial *q);
Polynomial* add(Polynomial *p, Polynomial *q);
int value(Polynomial *p, int x);
void printPolynomial(Polynomial *p, std::ostream &out);
void clearPolynomial(Polynomial *&p);