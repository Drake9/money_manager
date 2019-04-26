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
        income.setDate(Date::getCurrentDate());
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
        expense.setDate(Date::getCurrentDate());
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
    string currentDate = Date::getCurrentDate();

    int year = SupportiveMethods::convertStringToInt(currentDate.substr(0,4));
    int month = SupportiveMethods::convertStringToInt(currentDate.substr(5,2));

    Date periodStart(10000 * year + 100 * month + 1);
    Date periodEnd(10000 * year + 100 * month + periodEnd.countDaysInMonth(year, month));

    viewBalance(periodStart, periodEnd);
}

void TransactionsManager::viewLastMonthBalance(){
    string currentDate = Date::getCurrentDate();

    int year = SupportiveMethods::convertStringToInt(currentDate.substr(0,4));
    int month = SupportiveMethods::convertStringToInt(currentDate.substr(5,2));

    if(month == 1){
        Date periodStart(10000 * (year-1) + 1201);
        Date periodEnd(10000 * (year-1) + 1231);
        viewBalance(periodStart, periodEnd);
    }
    else{
        Date periodStart(10000 * year + 100 * (month-1) + 1);
        Date periodEnd(10000 * year + 100 * (month-1) + periodEnd.countDaysInMonth(year, month-1));
        viewBalance(periodStart, periodEnd);
    }
}

void TransactionsManager::viewCustomBalance(){
    Date periodStart, periodEnd;
    system("cls");

    do{
        cout << "Podaj date poczatkowa bilansu formacie RRRR-MM-DD: ";
    }while(!periodStart.setDateAndConfirm(SupportiveMethods::inputLine()));

    do{
        cout << "Podaj date koncowa bilansu formacie RRRR-MM-DD: ";
    }while(!periodEnd.setDateAndConfirm(SupportiveMethods::inputLine()));

    viewBalance(periodStart, periodEnd);
}

void TransactionsManager::viewBalance(Date periodStart, Date periodEnd){
    vector <Income> currentIncomes;
    vector <Expense> currentExpenses;
    Money incomeSum, expenseSum;

    system("cls");

    for (int i=0; i<incomes.size(); i++){
        if(incomes[i].getDate() >= periodStart.getDate() && incomes[i].getDate() <= periodEnd.getDate()){
            currentIncomes.push_back(incomes[i]);
            incomeSum += incomes[i].getAmount();
        }
    }
    sort(currentIncomes.begin(), currentIncomes.end());

    for (int i=0; i<expenses.size(); i++){
        if(expenses[i].getDate() >= periodStart.getDate() && expenses[i].getDate() <= periodEnd.getDate()){
            currentExpenses.push_back(expenses[i]);
            expenseSum += expenses[i].getAmount();
        }
    }
    sort(currentExpenses.begin(), currentExpenses.end());

    cout << "BILANS ZA OKRES " << periodStart.getDateAsString() << " - " << periodEnd.getDateAsString() << endl << endl;

    cout << "PRZYCHODY: " << endl;

    for(int i=0; i<currentIncomes.size(); i++)
        currentIncomes[i].printIncome();

    cout << endl << "WYDATKI: " << endl;

    for(int i=0; i<currentExpenses.size(); i++)
        currentExpenses[i].printExpense();

    cout << endl << "SUMA PRZYCHODOW: " << incomeSum.getAmountAsString();
    cout << endl << "SUMA WYDATKOW: " << expenseSum.getAmountAsString();

    Money difference = incomeSum - expenseSum;
    if(difference.getAmount() >= 0){
        cout << endl << endl << "OSZCZEDNOSCI: " << difference.getAmountAsString() << endl << endl;
    }
    else{
        difference = expenseSum - incomeSum;
        cout << endl << endl << "DLUG: " << difference.getAmountAsString() << endl << endl;
    }

    system("pause");
}
