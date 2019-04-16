#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include "MoneyManager.h"

using namespace std;

int main(){

    MoneyManager moneyManager("users.xml", "incomes.xml", "expenses.xml");

    char choice;

    while (true)
    {
        if (!moneyManager.ifUserIsLoggedIn())
        {
            choice = moneyManager.chooseMainMenuOption();

            switch (choice)
            {
            case '1':
                moneyManager.logUserIn();
                break;
            case '2':
                moneyManager.registerUser();
                break;
            case '0':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = moneyManager.chooseUserMenuOption();

            switch (choice)
            {
            case '1':
                moneyManager.addIncome();
                break;
            case '2':
                moneyManager.addExpense();
                break;
            case '3':
                moneyManager.viewCurrentMonthBalance();
                break;
            case '4':
                moneyManager.viewLastMonthBalance();
                break;
            case '5':
                moneyManager.viewCustomBalance();
                break;
            case '7':
                moneyManager.changeUserPassword();
                break;
            case '9':
                moneyManager.logUserOut();
                break;
            }
        }
    }
    return 0;
}
