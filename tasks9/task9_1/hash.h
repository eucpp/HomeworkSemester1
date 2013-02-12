#pragma once

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>

int getCode(char ch);
unsigned int sumHash(char *str, unsigned int mod);
unsigned int longSumHash(char *str, unsigned int mod);


//void hashFuncStat();
//char* getRandomStr(bool init);
//void getCodeTest();