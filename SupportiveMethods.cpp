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

string SupportiveMethods::convertTableToString(char *table, int tableSize){
    string output = "";

    for(int i=0; i<tableSize; i++){
        output += table[i];
    }
    return output;
}
