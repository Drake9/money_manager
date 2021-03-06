#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <time.h>

using namespace std;

#ifndef SUPPORTIVE_METHODS_H
#define SUPPORTIVE_METHODS_H

class SupportiveMethods{

public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static bool ifFileIsEmpty(fstream &file);
    static char inputChar();
    static string changeFirstLetterToUppercaseAndOtherToLowercase(string text);
    static string inputLine();
    static int inputInteger();
    static string convertTableToString(char *table, int tableSize);
};

#endif
