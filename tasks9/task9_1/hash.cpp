#include "hash.h"

using std::cout;
using std::cin;
using std::endl;

long int raisingTo(int a, int n)
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
	long int temp = raisingTo(a, degree);
	long int sqr = temp * temp;
	if (n % 2 == 0)
	{
		return sqr;
	}
	else
	{
		return sqr * a;
	}
}
int getCode(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - 48;
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		return ch - 55;
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		return ch - 87;
	}
	else
	{
		return 36;
	}
}
char getCh(int code)
{
	if (code >= 0 && code <= 9)
	{
		return code + 48;
	}
	else if (code >= 10 && code <= 35)
	{
		return code + 87;
	}
	else
	{
		return ' ';
	}
}

unsigned int sumHash(char *str, unsigned int mod)
{
	const int base = 37;
	int len = strlen(str);
	unsigned int hash = 0;
	for (int i = 0; i < len; i++)
	{
		int code = getCode(str[i]);
		int digit = i;
		int tmp = code * raisingTo(base, digit);
		hash += tmp % mod;
	}
	return hash % mod;
}
unsigned int longSumHash(char *str, unsigned int mod)
{
	const int bufferSize = 200;
	unsigned int hash = 0;
	int length = strlen(str);
	int i = 0;
	while (length > 0)
	{
		if (getCode(str[i]) == 36)
		{
			i++;
			length--;
			continue;
		}
		char buffer[bufferSize] = {'\0'};
		int j = 0;
		while (length > 0 && getCode(str[i]) != 36)
		{
			buffer[j] = str[i];
			i++;
			j++;
			length--;
		}
		char *word = new char[strlen(buffer) + 1];
		strcpy(word, buffer);
		unsigned int wordHash = sumHash(word, mod);
		if (wordHash > 0xFFFFFFFF - hash)
		{
			hash = (wordHash - (0xFFFFFFFF - hash)) % mod;
		}
		else
		{
			hash = (hash + wordHash) % mod;
		}
		delete[] word;
	}
	return hash;
}