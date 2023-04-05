#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>

#include "UserManager.h"
#include "IncomesExpensesManager.h"

using namespace std;

class FinanceManager {
    UserManager userManager;
    const string INCOMESFILENAME;
    const string EXPENSESFILENAME;
    IncomesExpensesManager* incomesExpensesManager;

public:
    FinanceManager(string usersFileName, string incomesFileName, string expensesFileName)
        : userManager(usersFileName), INCOMESFILENAME(incomesFileName), EXPENSESFILENAME(expensesFileName)
    {
        incomesExpensesManager = NULL;
    };
    ~FinanceManager()
    {
        delete incomesExpensesManager;
        incomesExpensesManager = NULL;
    };
    int getIdOfLoggedUser();
    void setIdOfLoggedUser(int newId);
    void registration();
    void logIn ();
    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displayBalanceFromChosenPeriod();
    void changePassword();
    void logout();
};

#endif
