#include <iostream>
#include <time.h>
#include <conio.h>
#include "Markup.h"
#include "SupportiveMethods.h"
#include "Money.h"

using namespace std;

class Transaction{

protected:

    const int MINIMAL_YEAR = 2000;
    const int MINIMAL_MONTH = 1;
    const int MAXIMAL_MONTH = 12;
    const int MINIMAL_DAY = 1;

    int userID;
    int date;
    string item;
    Money amount;

    bool validateString(string text);
    bool validateDate(int year, int month, int day);
    int countDaysInMonth(int customYear, int customMonth);

public:

    int getUserID();
    string getDateAsString();
    string getItem();
    Money getAmount();

    void setUserID(int newID);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    void printTransaction();

};

class Income :public Transaction{

    int incomeID;

public:

    int getIncomeID();
    void setIncomeID(int newID);
    void printIncome();

    string serialize();
    void deserialize(string strSubDoc);

    Income &operator = (const Income &income2);
};
