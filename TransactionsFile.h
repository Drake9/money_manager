#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Transaction.h"

using namespace std;

class TransactionsFile{

    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

    int lastIncomeID, lastExpenseID;

public:

    TransactionsFile(string incomesFileName, string expensesFileName)
        : INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {};
    int getLastIncomeID();
    int getLastExpenseID();
    vector <Income> loadIncomesFromFile(int loggedInUserID);
    void writeAllIncomesToFile(vector <Income> &incomes);
    bool appendIncomeToFile(Income newIncome);
};
