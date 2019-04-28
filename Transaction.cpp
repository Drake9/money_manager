#include "Transaction.h"

using namespace std;

/**----- GETTERS & SETTERS ------**/

int Transaction::getUserID(){
    return userID;
}

int Transaction::getDate(){
    return date.getDate();
}

string Transaction::getDateAsString(){
    return date.getDateAsString();
}

string Transaction::getItem(){
    return item;
}

Money Transaction::getAmount(){
    return amount;
}


void Transaction::setUserID(int newID){
    userID = newID;
}

void Transaction::setDate(string newDate){
    date.setDate(newDate);
}

bool Transaction::setDateAndConfirm(string newDate){
    return date.setDateAndConfirm(newDate);
}

void Transaction::setItem(string newItem){
    item = newItem;
}

void Transaction::setAmount(string newAmount){
    amount.setAmount(newAmount);
}

/**--------------------------------**/

void Transaction::printTransaction(){
    cout << "date: " << date.getDateAsString() << "    ";
    cout << "amount: " << amount.getAmountAsString() <<  endl;
    cout << "item: " << item << endl;
}

/**------------ INCOME ----------------**/

Income::Income(){
    incomeID = 0;
    userID = 0;
    date.setDate(20010101);
    amount.setAmount(0);
    item = "";
}

void Income::setIncomeID(int newID){
    incomeID = newID;
}

int Income::getIncomeID(){
    return incomeID;
}

void Income::printIncome(){
    cout << endl << "incomeID: " << incomeID << "    ";
    printTransaction();
}

Income & Income::operator = (const Income &income2){
    this->incomeID = income2.incomeID;
    this->userID = income2.userID;
    this->date = income2.date;
    this->item = income2.item;
    this->amount = income2.amount;
}

string Income::serialize(){
    CMarkup xml;
    xml.AddElem("income");
    xml.IntoElem();
    xml.AddElem("incomeID", incomeID);
    xml.AddElem("userID", userID);
    xml.AddElem("date", date.getDateAsString());
    xml.AddElem("item", item);
    xml.AddElem("amount", amount.getAmountAsString());
    xml.OutOfElem();

    return xml.GetDoc();
}

void Income::deserialize(string strSubDoc){

    CMarkup xml( strSubDoc );

    xml.FindElem(); // income
    xml.IntoElem();

    if ( xml.FindElem("incomeID" ) )
        incomeID = SupportiveMethods::convertStringToInt(xml.GetData());
    else
        incomeID = 0;

    if ( xml.FindElem("userID" ) )
        userID = SupportiveMethods::convertStringToInt(xml.GetData());
    else
        userID = 0;

    if ( xml.FindElem("date") )
        date.setDate(xml.GetData());
    else
        date.setDate("2001-01-01");

    if ( xml.FindElem("item") )
        item = xml.GetData();
    else
        item = "";

    if ( xml.FindElem("amount") )
        amount.setAmount(xml.GetData());
    else
        amount.setAmount(0);
}

/**------------ EXPENSE --------------**/

Expense::Expense(){
    expenseID = 0;
    userID = 0;
    date.setDate(20010101);
    amount.setAmount(0);
    item = "";
}

void Expense::setExpenseID(int newID){
    expenseID = newID;
}

int Expense::getExpenseID(){
    return expenseID;
}

void Expense::printExpense(){
    cout << endl << "expenseID: " << expenseID << "    ";
    printTransaction();
}

Expense & Expense::operator = (const Expense &expense2){
    this->expenseID = expense2.expenseID;
    this->userID = expense2.userID;
    this->date = expense2.date;
    this->item = expense2.item;
    this->amount = expense2.amount;
}

string Expense::serialize(){
    CMarkup xml;
    xml.AddElem("expense");
    xml.IntoElem();
    xml.AddElem("expenseID", expenseID);
    xml.AddElem("userID", userID);
    xml.AddElem("date", date.getDateAsString());
    xml.AddElem("item", item);
    xml.AddElem("amount", amount.getAmountAsString());
    xml.OutOfElem();

    return xml.GetDoc();
}

void Expense::deserialize(string strSubDoc){

    CMarkup xml( strSubDoc );

    xml.FindElem(); // income
    xml.IntoElem();

    if ( xml.FindElem("expenseID" ) )
        expenseID = SupportiveMethods::convertStringToInt(xml.GetData());
    else
        expenseID = 0;

    if ( xml.FindElem("userID" ) )
        userID = SupportiveMethods::convertStringToInt(xml.GetData());
    else
        userID = 0;

    if ( xml.FindElem("date") )
        date.setDate(xml.GetData());
    else
        date.setDate("2001-01-01");

    if ( xml.FindElem("item") )
        item = xml.GetData();
    else
        item = "";

    if ( xml.FindElem("amount") )
        amount.setAmount(xml.GetData());
    else
        amount.setAmount(0);
}

/***************************************/

bool operator < (const Transaction &deal1, const Transaction &deal2){
    return (deal1.date < deal2.date);
}
