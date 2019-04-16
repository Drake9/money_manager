#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include "UsersManager.h"
#include "TransactionsManager.h"

using namespace std;

class MoneyManager{

    UsersManager usersManager;
    TransactionsManager *transactionsManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:

    MoneyManager(string usersFileName, string incomesFileName, string expensesFileName)
        :usersManager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {
        transactionsManager = NULL;
    };
    ~MoneyManager(){
        delete transactionsManager;
        transactionsManager = NULL;
    };
    bool ifUserIsLoggedIn();
    int getLoggedInUserID();
    char chooseMainMenuOption();
    char chooseUserMenuOption();
    void registerUser();
    void printAllUsers();
    void logUserIn();
    void logUserOut();
    void changeUserPassword();
    void addIncome();
    void addExpense();
    void viewCurrentMonthBalance();
    void viewLastMonthBalance();
    void viewCustomBalance();
};
