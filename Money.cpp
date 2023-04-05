#include "Money.h"

void Money::setId(int newId) {
    if (newId > 0) {
        id = newId;
    }
}

void Money::setUserId(int newUserId) {
    if (newUserId > 0) {
        userId = newUserId;
    }
}

void Money::setDate(string newDate) {
    if ((int) newDate.size() == 10 && newDate[4] == '-' && newDate[7] == '-') {
        date = newDate;
    }
}

void Money::setItem(string newItem) {
    if ((int) newItem.size() >= 0) {
        item = newItem;
    }
}

void Money::setAmount(double newAmount) {
    if (newAmount > 0) {
        amount = newAmount;
    }
}

int Money::getId() {
    return id;
}

int Money::getUserId() {
    return userId;
}

string Money::getDate() {
    return date;
}

string Money::getItem() {
    return item;
}

double Money::getAmount() {
    return amount;
}
