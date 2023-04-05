#include "ExpensesFile.h"

string ExpensesFile::getExpensesFileName() {
    return FILENAME;
}

vector<Money> ExpensesFile::loadExpenses(int idOfLoggedUser) {
    vector<Money> expenses;
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Expense")) {
        Money expense;
        xml.IntoElem();
        xml.FindElem("Id");
        expense.setId(stoi(xml.GetData()));
        xml.FindElem("UserId");
        expense.setUserId(stoi(xml.GetData()));
        xml.FindElem("Date");
        expense.setDate(xml.GetData());
        xml.FindElem("Item");
        expense.setItem(xml.GetData());
        xml.FindElem("Amount");
        expense.setAmount(stod(xml.GetData()));
        xml.OutOfElem();
        if (expense.getUserId() == idOfLoggedUser) {
            expenses.push_back(expense);
        }
    }
    return expenses;
}

void ExpensesFile::addExpense(Money newExpense) {
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("Id", newExpense.getId());
    xml.AddElem("UserId", newExpense.getUserId());
    xml.AddElem("Date", newExpense.getDate());
    xml.AddElem("Item", newExpense.getItem());
    ostringstream s;
    s << fixed;
    s << setprecision(2);
    s << newExpense.getAmount();
    xml.AddElem("Amount", s.str());
    xml.OutOfElem();
    xml.Save(FILENAME);
}
