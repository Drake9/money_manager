#include <iostream>
#include "SupportiveMethods.h"

using namespace std;

string SupportiveMethods::convertIntToString(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

bool SupportiveMethods::ifFileIsEmpty(fstream &file){
    file.seekg(0, ios::end);
    if (file.tellg() == 0)
        return true;
    else
        return false;
}

char SupportiveMethods::inputChar(){
    string input = "";
    char character  = {0};

    while (true){
        getline(cin, input);

        if (input.length() == 1){
            character = input[0];
            break;
        }

        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string SupportiveMethods::getNumber(string text, int characterPosition){
    string number = "";
    while(isdigit(text[characterPosition]) == true)
    {
        number += text[characterPosition];
        characterPosition ++;
    }
    return number;
}

int SupportiveMethods::convertStringToInt(string number){
    int result;
    istringstream iss(number);
    iss >> result;

    return result;
}

string SupportiveMethods::changeFirstLetterToUppercaseAndOtherToLowercase(string text){
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string SupportiveMethods::inputLine(){
    string line = "";
    getline(cin, line);
    return line;
}

int SupportiveMethods::inputInteger(){
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie." << endl;
    }
    return number;
}

bool SupportiveMethods::deleteFile(string fileName){
    if (remove(fileName.c_str()) == 0)
        return true;
    else{
        cout << "Nie udalo sie usunac pliku." << fileName << endl;
        return false;
    }
}

bool SupportiveMethods::changeFileName(string fileName, string wantedFileName){
    if (rename(fileName.c_str(), wantedFileName.c_str()) == 0)
        return true;
    else{
        cout << "Nazwa pliku nie zostala zmieniona." << wantedFileName << endl;
        return false;
    }
}

string SupportiveMethods::convertTableToString(char *table, int tableSize){
    string output = "";

    for(int i=0; i<tableSize; i++){
        output += table[i];
    }
    return output;
}

string SupportiveMethods::getCurrentDate(){
    time_t currentTime;
    struct tm * data;
    char dateAsTable[11];
    string dateAsString = "";

    time( & currentTime );
    data = localtime( & currentTime );

    strftime(dateAsTable, 11, "%Y-%m-%d", data);
    dateAsString = SupportiveMethods::convertTableToString(dateAsTable, 10);
    return dateAsString;
}

int SupportiveMethods::countDaysInMonth(int year, int month){
    int table[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(year%4 != 0)
        return table[month-1];
    else{
        if(year%100 != 0)
            return 29;
        else{
            if(year%400 != 0)
                return 28;
            else
                return 29;
        }
    }
}
