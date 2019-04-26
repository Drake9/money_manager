#include <iostream>
#include "Date.h"

using namespace std;

/**-------  CONSTRUCTORS  -------**/

Date::Date(){
    date = 20010101;
}

Date::Date(int newDate){
    date = newDate;
}

Date::Date(string newDate){
    setDate(newDate);
}

/**-------  GETTERS & SETTERS  -------**/

int Date::getDate(){
    return date;
}

string Date::getDateAsString(){
    string output = SupportiveMethods::convertIntToString(date);

    output.insert(6, "-");
    output.insert(4, "-");

    return output;
}

void Date::setDate(int newDate){
    date = newDate;
}


void Date::setDate(string newDate){
    bool success = false;

    if(validateString(newDate)){
        int year = SupportiveMethods::convertStringToInt(newDate.substr(0,4));
        int month = SupportiveMethods::convertStringToInt(newDate.substr(5,2));
        int day = SupportiveMethods::convertStringToInt(newDate.substr(8,2));

        if(validateDate(year, month, day)){
            date = 10000 * year + 100 * month + day;
            success = true;
        }
    }

    if(success == false){
        cout << "Podana data jest nieprawidlowa." << endl;
        date = 20010101;
    }
}

bool Date::setDateAndConfirm(string newDate){
    bool success = false;

    if(validateString(newDate)){
        int year = SupportiveMethods::convertStringToInt(newDate.substr(0,4));
        int month = SupportiveMethods::convertStringToInt(newDate.substr(5,2));
        int day = SupportiveMethods::convertStringToInt(newDate.substr(8,2));

        if(validateDate(year, month, day)){
            date = 10000 * year + 100 * month + day;
            if(getMaximalDate() >= date)
                success = true;
        }
    }

    return success;
}

/**-------  VALIDATION  -------**/

bool Date::validateString(string text){
    if(text.size() != 10)
        return false;

    for(int i=0; i<10; i++){

        if(i == 4 || i == 7){
            if(text[i] != '-' && text[i] != '.')
                return false;
        }
        else{
            if(text[i] < '0' || text[i] > '9')
                return false;
        }
    }

    return true;
}

bool Date::validateDate(int customYear, int customMonth, int customDay){
    if(customYear < MINIMAL_YEAR)
        return false;
    if(customMonth < MINIMAL_MONTH)
        return false;
    if(customMonth > MAXIMAL_MONTH)
        return false;
    if(customDay < MINIMAL_DAY)
        return false;
    if(customDay > countDaysInMonth(customYear, customMonth))
        return false;

    return true;
}

int Date::countDaysInMonth(int year, int month){
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

int Date::getMaximalDate(){
    string currentDate = getCurrentDate();

    int year = SupportiveMethods::convertStringToInt(currentDate.substr(0,4));
    int month = SupportiveMethods::convertStringToInt(currentDate.substr(5,2));

    int day = countDaysInMonth(year, month);

    int maxDate = 10000 * year + 100 * month + day;

    return maxDate;
}

/*******************************/

string Date::getCurrentDate(){
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

/**-------  OPERATORS  -------**/

bool operator == (const Date &date1, const Date &date2){
    return (date1.date == date2.date);
}

bool operator != (const Date &date1, const Date &date2){
    return !(date1 == date2);
}

bool operator < (const Date &date1, const Date &date2){
    return (date1.date < date2.date);
}

bool operator > (const Date &date1, const Date &date2){
    return (date1.date > date2.date);
}

bool operator <= (const Date &date1, const Date &date2){
    return (date1.date <= date2.date);
}

bool operator >= (const Date &date1, const Date &date2){
    return (date1.date >= date2.date);
}

Date & Date::operator = (const Date &date2){
    this->date = date2.date;
}
