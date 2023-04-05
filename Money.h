#ifndef MONEY_H
#define MONEY_H

#include <iostream>

using namespace std;

class Money {
    int id;
    int userId;
    string date;
    string item;
    double amount;

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getId();
    int getUserId();
    string getDate();
    string getItem();
    double getAmount();
};

#endif
