#include <iostream>
#include "UsersFile.h"
#include "TransactionsFile.h"

using namespace std;

int main(){

    string customMoneyString = "";

    /*
        cout << "Podaj pierwsza kwote: ";
        cin >> customMoneyString;
        Money value1(customMoneyString);

        cout << "Podaj druga kwote: ";
        cin >> customMoneyString;
        Money value2(customMoneyString);

        if(value1 == value2)
            cout << "Kwoty sa rowne." << endl;
        else
            cout << "Nieprawda." << endl;

    /*

    /*********************/

    /*
    vector<User> users;

    UsersFile usersFile("users.xml");

    users = usersFile.loadUsersFromFile();

    for(vector <User>::iterator itr = users.begin(); itr != users.end(); itr++){
        itr->view();
    }
    */

    /*********************/

    vector<Income> incomes;

    TransactionsFile transactionsFile("incomes.xml");

    incomes = transactionsFile.loadIncomesFromFile();

    for(vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++){
        itr->printIncome();
    }

    return 0;
}
