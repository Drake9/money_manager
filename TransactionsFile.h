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
    vector <Income> loadUserIncomesFromFile(int loggedInUserID);
    vector <Expense> loadUserExpensesFromFile(int loggedInUserID);
    bool appendIncomeToFile(Income newIncome);
    bool appendExpenseToFile(Expense newExpense);
};
