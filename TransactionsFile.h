#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Transaction.h"

using namespace std;

class TransactionsFile{

    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:

    TransactionsFile(string incomesFileName, string expensesFileName)
        : INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {};
    vector <Income> loadIncomesFromFile(int loggedInUserID);
    void writeAllIncomesToFile(vector <Income> &incomes);
    bool appendIncomeToFile(Income income);
};
