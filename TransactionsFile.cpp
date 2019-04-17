#include "TransactionsFile.h"

using namespace std;

int TransactionsFile::getLastIncomeID(){
    return lastIncomeID;
}

int TransactionsFile::getLastExpenseID(){
    return lastExpenseID;
}

vector <Income> TransactionsFile::loadIncomesFromFile(int loggedInUserID){
    Income income;
    vector <Income> incomes;
    CMarkup xml;

    xml.Load( INCOMES_FILE_NAME.c_str() );

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem() ){
        income.deserialize(xml.GetSubDoc());
        incomes.push_back(income);
    }
    lastIncomeID = income.getIncomeID();

    return incomes;
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

bool TransactionsFile::appendIncomeToFile(Income newIncome){
    vector <Income> incomes;
    Income income;
    CMarkup xml;

    xml.Load( INCOMES_FILE_NAME.c_str() );

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem() ){
        income.deserialize(xml.GetSubDoc());
        incomes.push_back(income);
    }

    xml.AddSubDoc(newIncome.serialize());

    xml.OutOfElem();
    xml.Save( INCOMES_FILE_NAME.c_str() );

    return true;
}
