#include "IncomesExpensesManager.h"

void IncomesExpensesManager::addIncome() {
    Money newIncome;
    newIncome.setId(incomesFile.getTheBiggestId() == 0 ? 1 : incomesFile.getTheBiggestId() + 1);
    incomesFile.setTheBiggestId(newIncome.getId());
    newIncome.setUserId(ID_OF_LOGGED_USER);
    cout << "Do you want to add income with today's date? (y - yes, n - no):";
    string userInput = AuxiliaryFunctions::readLine();
    int tellUserAboutWrongInput = 0;

    if (userInput == "n") {
        do {
            if (tellUserAboutWrongInput > 0) {
                cout << "You have entered wrong date!" << endl;
            }
            cout << "Enter date of income (yyyy-mm-dd): ";
            userInput = AuxiliaryFunctions::readLine();
            tellUserAboutWrongInput++;
        } while (!AuxiliaryFunctions::checkDate(userInput));
    } else {
        userInput = AuxiliaryFunctions::getTodaysDate();
    }

    newIncome.setDate(userInput);
    cout << "Enter description of income: ";
    newIncome.setItem(AuxiliaryFunctions::readLine());
    tellUserAboutWrongInput = 0;
    string amountStr = "";

    do {
        if (tellUserAboutWrongInput > 0) {
            cout << "You have not entered a number!" << endl;
        }
        amountStr ="";
        cout << "Enter amount of income: ";
        userInput = AuxiliaryFunctions::readLine();
        tellUserAboutWrongInput++;
        for (int i = 0; i < (int) userInput.size(); i++) {
            if (userInput[i] == ',') {
                amountStr += ".";
            } else {
                amountStr += userInput[i];
            }
        }
    } while (!AuxiliaryFunctions::isNumber(amountStr));

    newIncome.setAmount(stod(amountStr));
    incomes.push_back(newIncome);
    incomesFile.addIncome(newIncome);
    cout << "New income has been added." << endl;
    system("pause");
}

void IncomesExpensesManager::addExpense() {
    Money newExpense;
    newExpense.setId(expensesFile.getTheBiggestId() == 0 ? 1 : expensesFile.getTheBiggestId() + 1);
    expensesFile.setTheBiggestId(newExpense.getId());
    newExpense.setUserId(ID_OF_LOGGED_USER);
    cout << "Do you want to add expense with today's date? (y - yes, n - no):";
    string userInput = AuxiliaryFunctions::readLine();
    int tellUserAboutWrongInput = 0;

    if (userInput == "n") {
        do {
            if (tellUserAboutWrongInput > 0) {
                cout << "You have entered wrong date!" << endl;
            }
            cout << "Enter date of expense (yyyy-mm-dd): ";
            userInput = AuxiliaryFunctions::readLine();
            tellUserAboutWrongInput++;
        } while (!AuxiliaryFunctions::checkDate(userInput));
    } else {
        userInput = AuxiliaryFunctions::getTodaysDate();
    }

    newExpense.setDate(userInput);
    cout << "Enter description of expense: ";
    newExpense.setItem(AuxiliaryFunctions::readLine());
    tellUserAboutWrongInput = 0;
    string amountStr = "";

    do {
        if (tellUserAboutWrongInput > 0) {
            cout << "You have not entered a number!" << endl;
        }
        amountStr ="";
        cout << "Enter amount of expense: ";
        userInput = AuxiliaryFunctions::readLine();
        tellUserAboutWrongInput++;
        for (int i = 0; i < (int) userInput.size(); i++) {
            if (userInput[i] == ',') {
                amountStr += ".";
            } else {
                amountStr += userInput[i];
            }
        }
    } while (!AuxiliaryFunctions::isNumber(amountStr));

    newExpense.setAmount(stod(amountStr));
    expenses.push_back(newExpense);
    expensesFile.addExpense(newExpense);
    cout << "New expense has been added." << endl;
    system("pause");
}

void IncomesExpensesManager::displayCurrentMonthBalance() {
    vector<Money> incomesSorted = incomes;
    vector<Money> expensesSorted = expenses;
    sort(incomesSorted.begin(), incomesSorted.end(), [] (Money& struct1, Money& struct2) {
        return (struct1.getDate() < struct2.getDate());
        }
    );
    sort(expensesSorted.begin(), expensesSorted.end(), [] (Money& struct1, Money& struct2) {
        return (struct1.getDate() < struct2.getDate());
        }
    );
    double incomesSum = 0;
    double expensesSum = 0;
    string dateToCompare = AuxiliaryFunctions::getTodaysDate().substr(0, 7);
    cout << "INCOMES" << endl;

    for (int i = 0; i < (int) incomesSorted.size(); i++) {
        if (dateToCompare == incomesSorted[i].getDate().substr(0, 7)) {
            cout << "Date of income: " << incomesSorted[i].getDate() <<
            " Amount of income: " << fixed << setprecision(2) << incomesSorted[i].getAmount() << endl;
            incomesSum += incomesSorted[i].getAmount();
        }
    }

    cout << "Incomes sum = " << incomesSum << endl;
    cout << "EXPENSES" << endl;

    for (int i = 0; i < (int) expensesSorted.size(); i++) {
        if (dateToCompare == expensesSorted[i].getDate().substr(0, 7)) {
            cout << "Date of expense: " << expensesSorted[i].getDate() <<
            " Amount of expense: " << expensesSorted[i].getAmount() << endl;
            expensesSum += expensesSorted[i].getAmount();
        }
    }

    cout << "Expenses sum = " << expensesSum << endl;
    cout << "Current month balance = " << incomesSum - expensesSum << endl;
    system("pause");
}

void IncomesExpensesManager::displayPreviousMonthBalance() {
    vector<Money> incomesSorted = incomes;
    vector<Money> expensesSorted = expenses;
    sort(incomesSorted.begin(), incomesSorted.end(), [] (Money& struct1, Money& struct2) {
        return (struct1.getDate() < struct2.getDate());
        }
    );
    sort(expensesSorted.begin(), expensesSorted.end(), [] (Money& struct1, Money& struct2) {
        return (struct1.getDate() < struct2.getDate());
        }
    );
    double incomesSum = 0;
    double expensesSum = 0;
    string currentMonth = AuxiliaryFunctions::getTodaysDate().substr(0, 7);
    string dateToComparePreviousMonth = "";
    if (currentMonth.substr(5) == "01") {
        dateToComparePreviousMonth = to_string((stoi(currentMonth.substr(0, 4)) - 1)) + "-12";
    } else if (stoi(currentMonth.substr(5)) - 1 < 10) {
        dateToComparePreviousMonth = currentMonth.substr(0, 5) + "0" + to_string((stoi(currentMonth.substr(5)) - 1));
    } else {
        dateToComparePreviousMonth = currentMonth.substr(0, 5) + to_string((stoi(currentMonth.substr(5)) - 1));
    }
    cout << "INCOMES" << endl;

    for (int i = 0; i < (int) incomesSorted.size(); i++) {
        if (dateToComparePreviousMonth == incomesSorted[i].getDate().substr(0, 7)) {
            cout << "Date of income: " << incomesSorted[i].getDate() <<
            " Amount of income: " << fixed << setprecision(2) << incomesSorted[i].getAmount() << endl;
            incomesSum += incomesSorted[i].getAmount();
        }
    }

    cout << "Incomes sum = " << incomesSum << endl;
    cout << "EXPENSES" << endl;

    for (int i = 0; i < (int) expensesSorted.size(); i++) {
        if (dateToComparePreviousMonth == expensesSorted[i].getDate().substr(0, 7)) {
            cout << "Date of expense: " << expensesSorted[i].getDate() <<
            " Amount of expense: " << expensesSorted[i].getAmount() << endl;
            expensesSum += expensesSorted[i].getAmount();
        }
    }

    cout << "Expenses sum = " << expensesSum << endl;
    cout << "Previous month balance = " << incomesSum - expensesSum << endl;
    system("pause");
}

void IncomesExpensesManager::displayBalanceFromChosenPeriod() {
    vector<Money> incomesSorted = incomes;
    vector<Money> expensesSorted = expenses;
    sort(incomesSorted.begin(), incomesSorted.end(), [] (Money& struct1, Money& struct2) {
        return (struct1.getDate() < struct2.getDate());
        }
    );
    sort(expensesSorted.begin(), expensesSorted.end(), [] (Money& struct1, Money& struct2) {
        return (struct1.getDate() < struct2.getDate());
        }
    );
    double incomesSum = 0;
    double expensesSum = 0;
    string startDate;
    string endDate;
    int tellUserAboutWrongInput = 0;

    do {
        if (tellUserAboutWrongInput > 0) {
            cout << "You have entered wrong date!" << endl;
        }
        cout << "Enter start date (yyyy-mm-dd): ";
        startDate = AuxiliaryFunctions::readLine();
        tellUserAboutWrongInput++;
    } while (!AuxiliaryFunctions::checkDate(startDate));

    tellUserAboutWrongInput = 0;

    do {
        if (tellUserAboutWrongInput > 0) {
            cout << "You have entered wrong date!" << endl;
        }
        cout << "Enter end date (yyyy-mm-dd): ";
        endDate = AuxiliaryFunctions::readLine();
        tellUserAboutWrongInput++;
    } while (!AuxiliaryFunctions::checkDate(endDate));

    int startDateFromUserInput = AuxiliaryFunctions::changeDateToInteger(startDate);
    int endDateFromUserInput = AuxiliaryFunctions::changeDateToInteger(endDate);
    cout << "INCOMES" << endl;

    for (int i = 0; i < (int) incomesSorted.size(); i++) {
        if (AuxiliaryFunctions::changeDateToInteger(incomesSorted[i].getDate()) >= startDateFromUserInput &&
            AuxiliaryFunctions::changeDateToInteger(incomesSorted[i].getDate()) <= endDateFromUserInput) {
            cout << "Date of income: " << incomesSorted[i].getDate() <<
            " Amount of income: " << fixed << setprecision(2) << incomesSorted[i].getAmount() << endl;
            incomesSum += incomesSorted[i].getAmount();
        }
    }

    cout << "Incomes sum = " << incomesSum << endl;
    cout << "EXPENSES" << endl;

    for (int i = 0; i < (int) expensesSorted.size(); i++) {
        if (AuxiliaryFunctions::changeDateToInteger(expensesSorted[i].getDate()) >= startDateFromUserInput &&
            AuxiliaryFunctions::changeDateToInteger(expensesSorted[i].getDate()) <= endDateFromUserInput) {
            cout << "Date of expense: " << expensesSorted[i].getDate() <<
            " Amount of expense: " << expensesSorted[i].getAmount() << endl;
            expensesSum += expensesSorted[i].getAmount();
        }
    }

    cout << "Expenses sum = " << expensesSum << endl;
    cout << "Balance from " << startDate << " to " << endDate << " = " << incomesSum - expensesSum << endl;
    system("pause");
}
