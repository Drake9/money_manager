#include <iostream>
#include <vector>
#include <windows.h>
#include "TransactionsFile.h"

using namespace std;

class TransactionsManager{

    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    TransactionsFile transactionsFile;

    Income inputNewIncomeData();
    Expense inputNewExpenseData();
    void viewTransactionData(Transaction transaction);
    void viewBalance(int periodStart, int periodEnd);

public:

    TransactionsManager(string incomesFileName, string expensesFileName, int loggedInUserID)
        : transactionsFile(incomesFileName, expensesFileName), LOGGED_IN_USER_ID(loggedInUserID)
    {
        incomes = transactionsFile.loadIncomesFromFile(LOGGED_IN_USER_ID);
        expenses = transactionsFile.loadExpensesFromFile(LOGGED_IN_USER_ID);
    };

    void addNewIncome();
    void addNewExpense();
    void viewCurrentMonthBalance();
    void viewLastMonthBalance();
    void viewCustomBalance();
};
