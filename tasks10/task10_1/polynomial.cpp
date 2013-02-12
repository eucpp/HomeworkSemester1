#include "polynomial.h"

using std::cout;
using std::cin;
using std::endl;


int raisingTo(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return a;
	}
	int degree = n / 2;
	int temp = raisingTo(a, degree);
	int sqr = temp * temp;
	if (n % 2 == 0)
	{
		return sqr;
	}
	else
	{
		return sqr * a;
	}
}
int strToInt(char *str)
{
	int len = strlen(str);
	bool sign = true;
	int start = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (len == 1)
		{
			if (str[0] == '+')
				return 1;
			else 
				return -1;
		}
		sign = (str[0] == '+');
		start = 1;
	}
	if (len == 0 || len > 10)
		return 0;
	int result = 0;
	for (int i = start; i < len; i++)
	{
		result += (str[i] - '0') * raisingTo(10, len - i - 1);
	}
	if (!sign)
		result *= -1;
	return result;
}

Monomial *copyMonomial(Monomial *monom);
void add(Polynomial *polynom, Monomial *monom);

Polynomial *createPolynomial()
{
	Polynomial *newP = new Polynomial;
	newP->head = nullptr;
	return newP;
}
Polynomial *createPolynomial(Polynomial *p)
{
	Polynomial *newP = new Polynomial;
	newP->head = nullptr;
	Monomial *ptr = p->head;
	while (ptr != nullptr)
	{
		add(newP, ptr);
		ptr = ptr->next;
	}
	return newP;
}

namespace States
{
	enum States
	{
		sign,
		coeff,
		deg_op,
		deg,
		success,
		error
	};
}

Polynomial* createPolynomial(char *str)
{
	int i = 0;
	Polynomial *polynom = createPolynomial();
	while (str[i] != '\0')
	{
		int state = States::sign;
		const int coeffSize = 10;
		char coeff[coeffSize] = {'\0'};
		const int degSize = 2;
		char deg[degSize] = {'\0'};
		int j = 0;
		Monomial *monom = new Monomial;
		monom->a = 1;
		monom->n = 1;
		monom->next = nullptr;
		monom->prev = nullptr;

		while (state != States::success && state != States::error && str[i] != '\0')
		{
			switch (state)
			{
			case States::sign:
				if (str[i] == ' ')
					++i;
				else if (str[i] == '+' || str[i] == '-')
				{
					coeff[j] = str[i];
					j++;
					i++;
					state = States::coeff;
					while (str[i] == ' ')
						i++;
				}
				else if (str[i] >= '0' && str[i] <= '9')
					{
						coeff[j] = str[i];
						j++;
						i++;
						state = States::coeff;
					}
				else if (str[i] == 'x')
				{
					if (j != 0)
						monom->a = strToInt(coeff);
					j = 0;
					state = States::deg_op;
					i++;
				}
				else
					state = States::deg_op;
				break;
			case States::coeff:
				if (str[i] >= '0' && str[i] <= '9')
					if (j < coeffSize)
					{
						coeff[j] = str[i];
						j++;
						i++;
					}
					else
						state = States::error;
				else if (str[i] == 'x')
				{
					if (j != 0)
						monom->a = strToInt(coeff);
					j = 0;
					state = States::deg_op;
					i++;
				}
				else if (str[i] == ' ')
				{
					++i;
					if (j != 0)
					{
						monom->a = strToInt(coeff);
						monom->n = 0;
						state = States::success;
					}
				}
				else
					state = States::error;
				break;	
			case States::deg_op:
				if (str[i] == '^')
				{
					state = States::deg;
					i++;
				}
				else if (str[i] == ' ')
				{
					state = States::success;
					i++;
				}
				else
					state = States::error;
				break;
			case States::deg:
				if (str[i] >= '0' && str[i] <= '9')
					{
						if (j < coeffSize)
						{
							deg[j] = str[i];
							j++;
							i++;
						}
						else
							state = States::error;
					}
				else if (str[i] == ' ')
				{
					if (j != 0)
					{
						monom->n = strToInt(deg);
						state = States::success;
						++i;
					}
					else
						state = States::error;
				}
				else
					state = States::error;
				break;
			}
		}

		if (state == States::success)
		{
			add(polynom, monom);
		}
		else
		{
			clearPolynomial(polynom);
			delete polynom;
			return nullptr;
		}
		delete monom;
	}
	return polynom;
}

void add(Polynomial *polynom, Monomial *monom)
{
	if (polynom == nullptr)
	{
		return;
	}
	Monomial *copy = copyMonomial(monom);
	if (polynom->head == nullptr)
	{
		polynom->head = copy;
		polynom->head->next = nullptr;
		polynom->head->prev = nullptr;
		return;
	}
	Monomial *ptr = polynom->head;
	while (ptr->next != nullptr && ptr->n > copy->n)
		ptr = ptr->next;

	if (ptr->n == copy->n)
	{
		ptr->a += copy->a;
		delete copy;
	}
	else if (ptr->n > copy->n)
		{
			copy->next = nullptr;
			copy->prev = ptr;
			ptr->next = copy;
		}
	else
	{
		if (ptr == polynom->head)
		{
			polynom->head->prev = copy;
			copy->next = polynom->head;
			polynom->head = copy;
		}
		else
		{
			copy->next = ptr;
			copy->prev = ptr->prev;
			ptr->prev->next = copy;
			ptr->prev = copy;
		}
	}
}

Polynomial* add(Polynomial *p, Polynomial *q)
{
	Polynomial *r = createPolynomial(p);
	if (q == nullptr || q->head == nullptr)
		return r;
	Monomial *ptr = q->head;
	while (ptr != nullptr)
	{
		add(r, ptr);
		ptr = ptr->next;
	}
	return r;
}

bool equals(Polynomial *p, Polynomial *q)
{
	if (p == nullptr && q == nullptr)
		return true;
	else if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
		return false;
	Monomial *ptr1 = p->head;
	Monomial *ptr2 = q->head;
	while (ptr1 != nullptr && ptr2 != nullptr)
	{
		if (ptr1->a != ptr2->a || ptr1->n != ptr2->n)
			return false;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	if (ptr1 != ptr2)
		return false;
	return true; 
}
int value(Polynomial *p, int x)
{
	if (p == nullptr || p->head == nullptr)
		return 0;
	Monomial *ptr = p->head;
	int result = 0;
	while (ptr != nullptr)
	{
		result += ptr->a * raisingTo(x, ptr->n);
		ptr = ptr->next;
	}
	return result;
}

void printPolynomial(Polynomial *p, std::ostream &out)
{
	if (p == nullptr)
		return;
	Monomial *ptr = p->head;
	bool first = true;
	while (ptr != nullptr)
	{
		if (ptr->n != 0 && ptr->a != 0)
		{
			if (!first)
					out << "+ ";
			if (ptr->a != 1)
			{
				out << ptr->a << "*";
			}
			out << "x";
			if (ptr->n != 1)
				out << "^" << ptr->n;
		}
		else if (ptr->a != 0)
			{
				if (!first)
					out << "+ ";
				out << ptr->a;
			}
		out << " ";
		first = false;
		ptr = ptr->next;
	}
	out << endl;
}

void clearPolynomial(Polynomial *&p)
{
	if (p == nullptr)
		return;
	while (p->head != nullptr)
	{
		Monomial *tmp = p->head;
		p->head = p->head->next;
		delete tmp;
	}
	delete p;
	p = nullptr;
}

Monomial *copyMonomial(Monomial *monom)
{
	Monomial *copy = new Monomial;
	copy->a = monom->a;
	copy->n = monom->n;
	copy->next = nullptr;
	copy->prev = nullptr;
	return copy;
}



