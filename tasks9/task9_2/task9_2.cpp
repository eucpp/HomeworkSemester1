#include <iostream>
#include <string.h>
#include <limits.h>

using std::cout;
using std::cin;
using std::endl;

unsigned long long int raisingTo(int a, int n)
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
	unsigned long long int temp = raisingTo(a, degree);
	unsigned long long int sqr = temp * temp;
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
bool strComp(char *str1, char *str2, int pos, int len)
{
	for (int i = pos; i < pos + len; i++)
	{
		if (str1[i] != str2[i - pos])
		{
			return false;
		}
	}
	return true;
}
const int hashBase = 37;
const int mod = 35993;

unsigned long long int hash(char *str, int length = -1)
{
	int len = length;
	if (len < 0)
	{
		len = strlen(str); 
	}
	unsigned long long int resultHash = 0;
	for (int i = 0; i < len; i++)
	{
		int code = getCode(str[i]);
		int digit = len - i - 1;
		unsigned long long int factor = raisingTo(hashBase, digit) % mod;
		unsigned long long int tmp = (code * factor) % mod; 
		resultHash += tmp;
	}
	return resultHash % mod;
}
unsigned long long int hash(char *str, unsigned int oldHash, int pos, int len)
{
	unsigned long long int resultHash = 0;
	unsigned long long int del = (getCode(str[pos - 1]) * raisingTo(hashBase, len - 1)) % mod;
	int add = getCode(str[pos + len - 1]) % mod;
	if (del > oldHash)
	{
		resultHash = mod - (del - oldHash);
	}
	else
	{
		resultHash = oldHash - del;
	}
	resultHash *= hashBase;
	resultHash = resultHash % mod;
	resultHash = (resultHash + add) % mod;
	return resultHash;
}
int rabinKarp(char *string, char *pattern)
{
	int strLen = strlen(string);
	int pLen = strlen(pattern);
	cout << strLen << " " << pLen << endl;
	if (pLen > strLen)
	{
		return -1;
	}
	unsigned long long int patternHash = hash(pattern);
	unsigned long long int substrHash = hash(string, pLen);
	if (substrHash == patternHash && strComp(string, pattern, 0, pLen))
	{
		return 0;
	}

	for (int i = 1; i <= strLen - pLen; ++i)
	{
		substrHash = hash(string, substrHash, i, pLen);
		if (substrHash == patternHash && strComp(string, pattern, i, pLen))
		{
			return i;
		}
	}
	return -1;
}
void test();
int main()
{
	//test();
	//cout << endl;

	const int strSize = 100;
	char string[strSize] = {'\0'};
	char pattern[strSize] = {'\0'};
	cout << "Enter string: " << endl;
	cin.getline(string, strSize);
	cout << "Enter pattern: " << endl;
	cin.getline(pattern, strSize);

	int pos = rabinKarp(string, pattern);
	if (pos == -1)
	{
		cout << "There isn't pattern in string" << endl;
	}
	else
	{
		cout << "There is a match starting with " << pos << " char " << endl;
	}

	int nothing;
	cin >> nothing;
	cout << endl;
	return 0;
}

/*
void test()
{
	char str[] = "";
	const int substrSize = 0;
	char substr[substrSize + 1] = {'\0'};
	unsigned long long int h = 0;
	for (int i = 0; i <= strlen(str) - substrSize; i++)
	{
		strncpy(substr, str + i, substrSize);
		cout << "String - " << substr << endl;
		unsigned long long int oldH = h;
		h = hash(substr);
		cout << "Standard hash: " << h << "; ";
		if (i != 0)
		{
			cout << "Recurrent hash: " << hash(str, oldH, i, substrSize);
		}
		cout << endl;
	}
}
*/