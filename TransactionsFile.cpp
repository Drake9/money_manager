#include "TransactionsFile.h"

using namespace std;

int TransactionsFile::getLastIncomeID(){
    return lastIncomeID;
}

int TransactionsFile::getLastExpenseID(){
    return lastExpenseID;
}

vector <Income> TransactionsFile::loadUserIncomesFromFile(int loggedInUserID){
    Income income;
    vector <Income> incomes;
    CMarkup xml;

    xml.Load( INCOMES_FILE_NAME.c_str() );

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem() ){
        income.deserialize(xml.GetSubDoc());
        if(income.getUserID() == loggedInUserID)
            incomes.push_back(income);
    }
    lastIncomeID = income.getIncomeID();

    return incomes;
}

vector <Expense> TransactionsFile::loadUserExpensesFromFile(int loggedInUserID){
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;

    xml.Load( EXPENSES_FILE_NAME.c_str() );

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem() ){
        expense.deserialize(xml.GetSubDoc());
        if(expense.getUserID() == loggedInUserID)
            expenses.push_back(expense);
    }
    lastExpenseID = expense.getExpenseID();

    return expenses;
}

void TransactionsFile::writeAllIncomesToFile(vector <Income> &incomes){
    CMarkup xml;
    xml.AddElem("incomes");
    xml.IntoElem();

    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++){
        xml.AddSubDoc(itr->serialize());
    }

    xml.OutOfElem();
    xml.Save( INCOMES_FILE_NAME.c_str() );
}

void TransactionsFile::writeAllExpensesToFile(vector <Expense> &expenses){
    CMarkup xml;
    xml.AddElem("expenses");
    xml.IntoElem();

    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++){
        xml.AddSubDoc(itr->serialize());
    }

    xml.OutOfElem();
    xml.Save( EXPENSES_FILE_NAME.c_str() );
}

bool TransactionsFile::appendIncomeToFile(Income newIncome){
    vector <Income> incomes;
    Income income;
    CMarkup xml;

    xml.Load( INCOMES_FILE_NAME.c_str() );

    if(!xml.FindElem("incomes")){
        xml.AddElem("incomes");
        xml.IntoElem();
    }
    else{
        xml.IntoElem();
        while ( xml.FindElem() ){
            income.deserialize(xml.GetSubDoc());
            incomes.push_back(income);
        }
    }
    xml.AddSubDoc(newIncome.serialize());

    xml.OutOfElem();
    xml.Save( INCOMES_FILE_NAME.c_str() );
    lastIncomeID++;

    return true;
}

bool TransactionsFile::appendExpenseToFile(Expense newExpense){
    vector <Expense> expenses;
    Expense expense;
    CMarkup xml;

    xml.Load( EXPENSES_FILE_NAME.c_str() );

    if(!xml.FindElem("expenses")){
        xml.AddElem("expenses");
        xml.IntoElem();
    }
    else{
        xml.IntoElem();
        while ( xml.FindElem() ){
            expense.deserialize(xml.GetSubDoc());
            expenses.push_back(expense);
        }
    }

    xml.AddSubDoc(newExpense.serialize());

    xml.OutOfElem();
    xml.Save( EXPENSES_FILE_NAME.c_str() );
    lastExpenseID++;

    return true;
}
