#include <iostream>
#include <time.h>
#include <conio.h>
#include "Markup.h"
#include "SupportiveMethods.h"
#include "Money.h"
#include "Date.h"

using namespace std;

class Transaction{

protected:

    int userID;
    Date date;
    string item;
    Money amount;

public:

    int getUserID();
    int getDate();
    string getDateAsString();
    string getItem();
    Money getAmount();

    void setUserID(int newID);
    void setDate(string newDate);
    bool setDateAndConfirm(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    void printTransaction();

    friend bool operator < (const Transaction &deal1, const Transaction &deal2);
};

class Income :public Transaction{

    int incomeID;

public:

    Income();
    int getIncomeID();
    void setIncomeID(int newID);
    void printIncome();

    string serialize();
    void deserialize(string strSubDoc);

    Income &operator = (const Income &income2);
};

class Expense :public Transaction{

    int expenseID;

public:

    Expense();
    int getExpenseID();
    void setExpenseID(int newID);
    void printExpense();

    string serialize();
    void deserialize(string strSubDoc);

    Expense &operator = (const Expense &expense2);
};
