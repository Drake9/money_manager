#include "Transaction.h"

using namespace std;

/**----- GETTERS & SETTERS ------**/

int Transaction::getUserID(){
    return userID;
}

string Transaction::getDateAsString(){
    string output = SupportiveMethods::convertIntToString(date);

    output.insert(6, "-");
    output.insert(4, "-");

    return output;
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

bool Transaction::validateString(string text){
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

bool Transaction::validateDate(int customYear, int customMonth, int customDay){
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

int Transaction::countDaysInMonth(int year, int month){
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

void Transaction::setItem(string newItem){
    item = newItem;
}

void Transaction::setAmount(string newAmount){
    amount.setAmount(newAmount);
}

/**--------------------------------**/

string Income::serialize(){
    CMarkup xml;
    xml.AddElem("income");
    xml.IntoElem();
    xml.AddElem("incomeID", incomeID);
    xml.AddElem("userID", userID);
    xml.AddElem("date", getDateAsString());
    xml.AddElem("item", "wynagrodzenie" );
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
        setDate(xml.GetData());
    else
        setDate("2001-01-01");

    if ( xml.FindElem("item") )
        item = xml.GetData();
    else
        item = "";

    if ( xml.FindElem("amount") )
        amount.setAmount(xml.GetData());
    else
        amount.setAmount(0);

}

void Transaction::printTransaction(){
    cout << "userID: " << userID << endl;
    cout << "date: " << getDateAsString() << endl;
    cout << "item: " << item << endl;
    cout << "amount: " << amount.getAmountAsString() << endl;
}

/**------------ INCOME ----------------**/

void Income::setIncomeID(int newID){
    incomeID = newID;
}

int Income::getIncomeID(){
    return incomeID;
}

void Income::printIncome(){
    cout << endl << "incomeID: " << incomeID << endl;
    printTransaction();
}

Income & Income::operator = (const Income &income2){
    this->incomeID = income2.incomeID;
    this->userID = income2.userID;
    this->date = income2.date;
    this->item = income2.item;
    this->amount = income2.amount;
}

/**------------ EXPENSE --------------**/

void Expense::setExpenseID(int newID){
    expenseID = newID;
}

int Expense::getExpenseID(){
    return expenseID;
}

void Expense::printExpense(){
    cout << endl << "expenseID: " << expenseID << endl;
    printTransaction();
}

Expense & Expense::operator = (const Expense &expense2){
    this->expenseID = expense2.expenseID;
    this->userID = expense2.userID;
    this->date = expense2.date;
    this->item = expense2.item;
    this->amount = expense2.amount;
}
