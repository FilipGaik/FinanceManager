#include "FinanceManager.h"

int FinanceManager::getIdOfLoggedUser() {
    return userManager.getIdOfLoggedUser();
}

void FinanceManager::setIdOfLoggedUser(int newId) {
    userManager.setIdOfLoggedUser(newId);
}

void FinanceManager::registration() {
    userManager.registration();
}

void FinanceManager::logIn() {
    userManager.logIn();
    if (getIdOfLoggedUser() > 0) {
        incomesExpensesManager = new IncomesExpensesManager(INCOMESFILENAME, EXPENSESFILENAME, userManager.getIdOfLoggedUser());
    }
}

void FinanceManager::addIncome() {
    incomesExpensesManager -> addIncome();
}

void FinanceManager::addExpense() {
    incomesExpensesManager -> addExpense();
}

void FinanceManager::displayCurrentMonthBalance() {
    incomesExpensesManager -> displayCurrentMonthBalance();
}

void FinanceManager::displayPreviousMonthBalance() {
    incomesExpensesManager -> displayPreviousMonthBalance();
}

void FinanceManager::displayBalanceFromChosenPeriod() {
    incomesExpensesManager -> displayBalanceFromChosenPeriod();
}

void FinanceManager::changePassword() {
    userManager.changePassword();
}

void FinanceManager::logout() {
    userManager.setIdOfLoggedUser(0);
    delete incomesExpensesManager;
    incomesExpensesManager = NULL;
}
