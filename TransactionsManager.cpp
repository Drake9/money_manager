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
        income.setDate(SupportiveMethods::getCurrentDate());
    }
    else{
        do{
            cout << "Podaj date przychodu w formacie RRRR-MM-DD - maksymalnie ostatni dzien biezacego miesiaca: ";
        }while(!income.setDateAndConfirm(SupportiveMethods::inputLine()));
    }

    cout << "Podaj tytul przychodu: ";
    income.setItem(SupportiveMethods::inputLine());

    cout << "Podaj kwote przychodu: ";
    income.setAmount(SupportiveMethods::inputLine());

    return income;
}

Expense TransactionsManager::inputNewExpenseData(){
    Expense expense;

    expense.setExpenseID(transactionsFile.getLastExpenseID()+1);
    expense.setUserID(LOGGED_IN_USER_ID);

    char choice = 'a';

    do{
        cout << "Wybierz 'T', aby dodac wydatek z dzisiejsza data, lub 'N', aby wybrac inna date wydatku: ";
        choice = SupportiveMethods::inputChar();
    }while(choice != 't' && choice != 'T' && choice != 'N' && choice != 'n');

    if(choice == 'T' || choice == 't'){
        expense.setDate(SupportiveMethods::getCurrentDate());
    }
    else{
        do{
            cout << "Podaj date wydatku w formacie RRRR-MM-DD - maksymalnie ostatni dzien biezacego miesiaca: ";
        }while(!expense.setDateAndConfirm(SupportiveMethods::inputLine()));
    }

    cout << "Podaj tytul wydatku: ";
    expense.setItem(SupportiveMethods::inputLine());

    cout << "Podaj kwote wydatku: ";
    expense.setAmount(SupportiveMethods::inputLine());

    return expense;
}

void TransactionsManager::viewCurrentMonthBalance(){
    string currentDate = SupportiveMethods::getCurrentDate();

    int year = SupportiveMethods::convertStringToInt(currentDate.substr(0,4));
    int month = SupportiveMethods::convertStringToInt(currentDate.substr(5,2));

    int periodStart = 10000 * year + 100 * month + 1;
    int periodEnd = 10000 * year + 100 * month + SupportiveMethods::countDaysInMonth(year, month);

    viewBalance(periodStart, periodEnd);
}

void TransactionsManager::viewBalance(int periodStart, int periodEnd){
    vector <Income> currentIncomes;
    vector <Expense> currentExpenses;
    Money incomeSum, expenseSum;

    system("cls");

    for (int i=0; i<incomes.size(); i++){
        if(incomes[i].getDate() >= periodStart && incomes[i].getDate() <= periodEnd){
            currentIncomes.push_back(incomes[i]);
            incomeSum += incomes[i].getAmount();
        }
    }
    sort(currentIncomes.begin(), currentIncomes.end());

    for (int i=0; i<expenses.size(); i++){
        if(expenses[i].getDate() >= periodStart && expenses[i].getDate() <= periodEnd){
            currentExpenses.push_back(expenses[i]);
            expenseSum += expenses[i].getAmount();
        }
    }
    sort(currentExpenses.begin(), currentExpenses.end());

    cout << "BILANS ZA OKRES " << periodStart << " - " << periodEnd << endl << endl;

    cout << "PRZYCHODY: " << endl;

    for(int i=0; i<currentIncomes.size(); i++)
        currentIncomes[i].printIncome();

    cout << endl << "WYDATKI: " << endl;

    for(int i=0; i<currentExpenses.size(); i++)
        currentExpenses[i].printExpense();

    cout << endl << "SUMA PRZYCHODOW: " << incomeSum.getAmountAsString();
    cout << endl << "SUMA WYDATKOW: " << expenseSum.getAmountAsString();

    Money difference;
    if(incomeSum.getAmount() >= expenseSum.getAmount()){
        difference = incomeSum - expenseSum;
        cout << endl << endl << "OSZCZEDNOSCI: " << difference.getAmountAsString() << endl;
    }
    else{
        difference = expenseSum - incomeSum;
        cout << endl << endl << "DLUG: " << difference.getAmountAsString() << endl;
    }

    system("pause");
}
