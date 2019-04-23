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
    {
        lastIncomeID = 0;
        lastExpenseID = 0;
    };
    int getLastIncomeID();
    int getLastExpenseID();
    vector <Income> loadIncomesFromFile(int loggedInUserID);
    vector <Expense> loadExpensesFromFile(int loggedInUserID);
    void writeAllIncomesToFile(vector <Income> &incomes);
    void writeAllExpensesToFile(vector <Expense> &expenses);
    bool appendIncomeToFile(Income newIncome);
    bool appendExpenseToFile(Expense newExpense);
};
