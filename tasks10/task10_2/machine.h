#pragma once

#include <iostream>
#include <fstream>
#include <string.h>
#include "list.h"

class Machine
{
	public:
		Machine(char*) throw(int);
		Machine::~Machine();
		void move(char ch);
		bool endOfWord();
		bool isCorrect();
		char* getWord();
		void reset();
		//void test();
	private:
		void clear();

		int **transTable;
		List **alphabet;
		int statesCount;
		int alphSize;
		int succState;
		int errState;

		int state;
		int ptr;
		static const int buffSize = 200;
		char word[buffSize];
};
