#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

#ifndef SUPPORTIVE_METHODS_H
#define SUPPORTIVE_METHODS_H

class SupportiveMethods{

public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static bool ifFileIsEmpty(fstream &file);
    static char inputChar();
    static string getNumber(string text, int characterPosition);
    static string changeFirstLetterToUppercaseAndOtherToLowercase(string text);
    static string inputLine();
    static int inputInteger();
    static bool deleteFile(string fileName);
    static bool changeFileName(string fileName, string wantedFileName);
    static string convertTableToString(char *table, int tableSize);
};

#endif
