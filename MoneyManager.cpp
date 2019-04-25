#include "MoneyManager.h"

using namespace std;

char MoneyManager::chooseMainMenuOption(){
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Logowanie" << endl;
    cout << "2. Rejestracja" << endl;
    cout << "---------------------------" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportiveMethods::inputChar();

    return choice;
}

char MoneyManager::chooseUserMenuOption(){
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Pokaz bilans z biezacego miesiaca" << endl;
    cout << "4. Pokaz bilans z poprzedniego miesiaca" << endl;
    cout << "5. Pokaz bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "---------------------------" << endl;
    cout << "9. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportiveMethods::inputChar();

    return choice;
}

bool MoneyManager::ifUserIsLoggedIn(){
    return usersManager.ifUserIsLoggedIn();
}

int MoneyManager::getLoggedInUserID(){
    return usersManager.getLoggedInUserID();
}

void MoneyManager::registerUser(){
    usersManager.registerUser();
}

void MoneyManager::printAllUsers(){
    usersManager.printAllUsers();
}

void MoneyManager::logUserIn(){
    usersManager.logUserIn();

    if(usersManager.ifUserIsLoggedIn()){
        transactionsManager = new TransactionsManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, usersManager.getLoggedInUserID());
    }
}

void MoneyManager::logUserOut(){
    usersManager.logUserOut();
    delete transactionsManager;
    transactionsManager = NULL;
}

void MoneyManager::changeUserPassword(){
    usersManager.changeUserPassword();
}

void MoneyManager::addIncome(){
    transactionsManager->addNewIncome();
}

void MoneyManager::addExpense(){
    transactionsManager->addNewExpense();
}

void MoneyManager::viewCurrentMonthBalance(){
    transactionsManager->viewCurrentMonthBalance();
}

void MoneyManager::viewLastMonthBalance(){
    ;
    //transactionsManager->viewLastMonthBalance();
}

void MoneyManager::viewCustomBalance(){
    ;
    //transactionsManager->viewCustomBalance();
}
