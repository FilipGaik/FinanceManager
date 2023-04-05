#ifndef INCOMESEXPENSESMANAGER_H
#define INCOMESEXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "Money.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class IncomesExpensesManager {
    vector<Money> incomes;
    vector<Money> expenses;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    const int ID_OF_LOGGED_USER;

public:
    IncomesExpensesManager(string incomesFileName, string expensesFileName, int idOfLoggedUser)
        : incomesFile(incomesFileName), expensesFile(expensesFileName), ID_OF_LOGGED_USER(idOfLoggedUser)
    {
        incomes = incomesFile.loadIncomes(ID_OF_LOGGED_USER);
        expenses = expensesFile.loadExpenses(ID_OF_LOGGED_USER);
    };
    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displayBalanceFromChosenPeriod();
};

#endif
