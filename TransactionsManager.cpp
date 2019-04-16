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
    /*
    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());
    */
    return income;
}
