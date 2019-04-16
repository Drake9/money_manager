#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Transaction.h"

using namespace std;

class TransactionsFile{

    const string INCOMES_FILE_NAME;

public:

    TransactionsFile(string incomesFileName): INCOMES_FILE_NAME(incomesFileName){};
    vector <Income> loadIncomesFromFile();
    void writeAllIncomesToFile(vector <Income> &incomes);
};
