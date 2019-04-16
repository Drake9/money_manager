#include <iostream>
#include "Markup.h"
#include "SupportiveMethods.h"

using namespace std;

class Money{

    const string CURRENCY_SYMBOL = "PLN";

    int amount;

    bool validateString(string text);

public:

    Money();
    Money(int amount);
    Money(string amount);

    void setAmount(int amount);
    void setAmount(string amount);

    string getAmountAsString();

    string serialize();
    void deserialize(string strSubDoc);

    friend Money operator + (const Money &money1, const Money &money2);
    friend Money operator - (const Money &money1, const Money &money2);
    friend Money operator * (const Money &money, const int &number);
    friend Money operator * (const int &number, const Money &money);
    friend int operator / (const Money &money1, const Money &money2);
    friend Money operator / (const Money &money, const int &number);
    friend bool operator == (const Money &money1, const Money &money2);
    Money &operator = (const Money &money2);
};
