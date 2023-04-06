#include "IncomesFile.h"

string IncomesFile::getIncomesFileName() {
    return FILENAME;
}

vector<Money> IncomesFile::loadIncomes(int idOfLoggedUser) {
    vector<Money> incomes;
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Income")) {
        Money income;
        xml.IntoElem();
        xml.FindElem("Id");
        income.setId(stoi(xml.GetData()));
        theBiggestId = income.getId();
        xml.FindElem("UserId");
        income.setUserId(stoi(xml.GetData()));
        xml.FindElem("Date");
        income.setDate(xml.GetData());
        xml.FindElem("Item");
        income.setItem(xml.GetData());
        xml.FindElem("Amount");
        income.setAmount(stod(xml.GetData()));
        xml.OutOfElem();
        if (income.getUserId() == idOfLoggedUser) {
            incomes.push_back(income);
        }
    }

    return incomes;
}

void IncomesFile::addIncome(Money newIncome) {
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("Id", newIncome.getId());
    xml.AddElem("UserId", newIncome.getUserId());
    xml.AddElem("Date", newIncome.getDate());
    xml.AddElem("Item", newIncome.getItem());
    ostringstream s;
    s << fixed;
    s << setprecision(2);
    s << newIncome.getAmount();
    xml.AddElem("Amount", s.str());
    xml.OutOfElem();
    xml.Save(FILENAME);
}
