#include "priorityTable.h"

const int tableSize = 4;
const char priorityTable[tableSize] = {'-', '+', '/', '*'};

int getPriority(char sign)
{
	for (int i = 0; i < tableSize; ++i)
	{
		if (sign == priorityTable[i])
		{
			return i;
		}
	}
	return -1;
}