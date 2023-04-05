#include <iostream>
#include "FinanceManager.h"

using namespace std;

int main() {
    string choiceFromReadLine;
    int choice;
    FinanceManager financeManager("users.xml", "incomes.xml", "expenses.xml");

    while (true) {
        if (financeManager.getIdOfLoggedUser() == 0) {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "FINANCE MANAGER" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cout << "1. Register." << endl;
            cout << "2. Log in." << endl;
            cout << "3. Exit." << endl;

            do {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout << "Choose option (1-3): ";
                choiceFromReadLine = AuxiliaryFunctions::readLine();
            } while (!AuxiliaryFunctions::isNumber(choiceFromReadLine));
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            choice = stoi(choiceFromReadLine);

            switch(choice) {
            case 1:
                financeManager.registration();
                break;
            case 2:
                financeManager.logIn();
                break;
            default:
                exit(0);
            }
        } else {
            do {
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                cout << "FINANCE MANAGER" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

                cout << "1. Add income." << endl;
                cout << "2. Add expense." << endl;
                cout << "3. Current month balance." << endl;
                cout << "4. Previous month balance." << endl;
                cout << "5. Balance from chosen period." << endl;
                cout << "6. Change password." << endl;
                cout << "7. Log out." << endl;

                do {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    cout << "Choose option (1-7): ";
                    choiceFromReadLine = AuxiliaryFunctions::readLine();
                } while (!AuxiliaryFunctions::isNumber(choiceFromReadLine));

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                choice = stoi(choiceFromReadLine);

                switch (choice) {
                case 1:
                    financeManager.addIncome();
                    break;
                case 2:
                    financeManager.addExpense();
                    break;
                case 3:
                    financeManager.displayCurrentMonthBalance();
                    break;
                case 4:
                    financeManager.displayPreviousMonthBalance();
                    break;
                case 5:
                    financeManager.displayBalanceFromChosenPeriod();
                    break;
                case 6:
                    financeManager.changePassword();
                    break;
                default:
                    financeManager.logout();
                }
            } while (choice >= 1 && choice < 7);
        }
    }
    return 0;
}
