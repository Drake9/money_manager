#include "TransactionsManager.h"

using namespace std;

void TransactionsManager::viewTransactionData(Transaction transaction){

    transaction.printTransaction();
}

void TransactionsManager::addNewIncome(){
    Income income;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = inputNewIncomeData();

    incomes.push_back(income);
    if(transactionsFile.appendIncomeToFile(income))
        cout << "Nowy przychod zostal dodany." << endl;
    else
        cout << "NIE udalo sie dodac nowego przychodu do pliku." << endl;
    system("pause");
}

void TransactionsManager::addNewExpense(){
    ;
    /*
    Expense expense;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = inputNewExpenseData();

    expenses.push_back(expense);
    if(transactionsFile.appendExpenseToFile(expense))
        cout << "Nowy wydatek zostal dodany." << endl;
    else
        cout << "NIE udalo sie dodac nowego wydatku do pliku." << endl;
    system("pause");
    */
}

Income TransactionsManager::inputNewIncomeData(){
    Income income;

    income.setIncomeID(transactionsFile.getLastIncomeID()+1);
    income.setUserID(LOGGED_IN_USER_ID);

    char choice = 'a';

    do{
        cout << "Wybierz 'T', aby dodac przychod z dzisiejsza data, lub 'N', aby wybrac inna date przychodu: ";
        choice = SupportiveMethods::inputChar();
    }while(choice != 't' && choice != 'T' && choice != 'N' && choice != 'n');

    if(choice == 'T' || choice == 't'){
        time_t currentTime;
        struct tm * data;
        char dateAsTable[11];
        string dateAsString = "";

        time( & currentTime );
        data = localtime( & currentTime );

        strftime(dateAsTable, 11, "%Y-%m-%d", data);
        dateAsString = SupportiveMethods::convertTableToString(dateAsTable, 10);
        income.setDate(dateAsString);
    }
    else{
        do{
            cout << "Podaj date przychodu w formacie RRRR-MM-DD: ";
        }while(!income.setDateAndConfirm(SupportiveMethods::inputLine()));
    }

    cout << "Podaj tytul przychodu: ";
    income.setItem(SupportiveMethods::inputLine());

    cout << "Podaj kwote przychodu: ";
    income.setAmount(SupportiveMethods::inputLine());

    return income;
}
