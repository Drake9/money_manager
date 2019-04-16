#include "TransactionsFile.h"

using namespace std;

vector <Income> TransactionsFile::loadIncomesFromFile(){
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
