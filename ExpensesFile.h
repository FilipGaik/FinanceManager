#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

#include "xmlFile.h"
#include "Money.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class ExpensesFile : public xmlFile{
public:
    ExpensesFile(string expensesFileName)
    : xmlFile(expensesFileName) {};
    vector<Money> loadExpenses(int idOfLoggedUser);
    string getExpensesFileName();
    void addExpense(Money newExpense);
};

#endif
