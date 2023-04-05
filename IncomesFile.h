#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

#include "xmlFile.h"
#include "Money.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class IncomesFile : public xmlFile{
public:
    IncomesFile(string incomesFileName)
    : xmlFile(incomesFileName) {};
    vector<Money> loadIncomes(int idOfLoggedUser);
    string getIncomesFileName();
    void addIncome(Money newIncome);
};

#endif
