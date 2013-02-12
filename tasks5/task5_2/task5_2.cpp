#include <stdlib.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printDouble(double d)
{
	unsigned long long int *bits = reinterpret_cast<unsigned long long int*>(&d);

	if (!(*bits << 1))
	{
		cout << 0 << endl;
		return;
	}
	
	unsigned long long int mask = 0;
	mask = ~ mask;
	mask <<= 63;

	if (*bits & mask)
	{
		cout << '-';
	}
	else
	{
		cout << '+';
	}

	unsigned long long mantissa = 0;
	int add = 1;
	unsigned long long int isEmptyMask = 0;
	isEmptyMask = ~ isEmptyMask;
	isEmptyMask >>= 12;
	mask >>= 12;
	unsigned long long max = 0;
	max = ~ max;
	max /= 10;
	int digits = 0;
	while ((*bits & isEmptyMask) && (mantissa < max))
	{
		mantissa *= 10;
		add *= 5;
		if (*bits & mask)
		{
			mantissa += add;
		}
		digits++;
		mask >>= 1;
		isEmptyMask >>= 1;
	}
	int mantsDigits = 0;
	unsigned long long int copy = mantissa;
	while (copy > 0)
	{
		copy /= 10;
		mantsDigits++;
	}
	if (mantissa != 0)
	{
		cout << "1.";
		for (int i = 0; i < digits - mantsDigits; ++i)
		{
			cout << '0';
		}
		cout << mantissa << " * ";
	}

	short int* tmp = reinterpret_cast<short int*>(bits);
	short int exp = tmp[3];
	exp &= 0x7FF0;
	exp >>= 4;
	exp -= 1023;
	cout << "2^" << exp;
}
int main()
{
	double doubleD;
	cin >> doubleD;
	cout << endl;
	printDouble(doubleD);

	cout << endl;
	int n;
	cin >> n;
	return 0;
}