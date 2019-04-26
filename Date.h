#include <iostream>
#include <time.h>
#include <conio.h>
#include "Markup.h"
#include "SupportiveMethods.h"

using namespace std;

class Date{

    const int MINIMAL_YEAR = 2000;
    const int MINIMAL_MONTH = 1;
    const int MAXIMAL_MONTH = 12;
    const int MINIMAL_DAY = 1;

    int date;

    bool validateString(string text);
    bool validateDate(int year, int month, int day);
    int getMaximalDate();

public:

    Date();
    Date(int newDate);
    Date(string newDate);

    void setDate(int newDate);
    void setDate(string newDate);
    bool setDateAndConfirm(string newDate);

    int getDate();
    string getDateAsString();

    static string getCurrentDate();
    static int countDaysInMonth(int customYear, int customMonth);

    friend bool operator == (const Date &date1, const Date &date2);
    friend bool operator != (const Date &date1, const Date &date2);
    friend bool operator < (const Date &date1, const Date &date2);
    friend bool operator > (const Date &date1, const Date &date2);
    friend bool operator <= (const Date &date1, const Date &date2);
    friend bool operator >= (const Date &date1, const Date &date2);
    Date &operator = (const Date &date2);
};
