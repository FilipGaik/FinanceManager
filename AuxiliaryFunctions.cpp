#include "AuxiliaryFunctions.h"

string AuxiliaryFunctions::readLine() {
    string line;
    cin.sync();
    getline(cin, line);
    return line;
}

bool AuxiliaryFunctions::isNumber(string line) {

    for (int i = 0; i < (int) line.size(); i++) {
        if (!isdigit(line[i]) && line[i] != '.') {
            return false;
        }
    }

    return true;
}

string AuxiliaryFunctions::getTodaysDate() {
    time_t now = time(0);
    struct tm* yet = localtime(&now);
    string month = to_string(yet -> tm_mon + 1);
        if ((int) month.size() == 1) {
            month = "0" + month;
        }
    string day = to_string(yet -> tm_mday);
        if ((int) day.size() == 1) {
            day = "0" + day;
        }
    string todaysDate = to_string(yet -> tm_year + 1900) + "-" + month + "-" + day;
    return todaysDate;
}

bool AuxiliaryFunctions::isALeapYear(string year) {
    int yearFromString = stoi(year);
    if ((yearFromString % 4 == 0 && yearFromString % 100 !=0) || yearFromString % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

bool AuxiliaryFunctions::checkDate(string userDate) {
    string currentDate = getTodaysDate();
    int currentYear = stoi(currentDate.substr(0, 4));
    int currentMonth = stoi(currentDate.substr(5, 2));
    int currentDay = stoi(currentDate.substr(8));
    if ((int) userDate.size() != 10 || userDate[4] != '-' || userDate[7] != '-') {
        return false;
    }
    int year = stoi(userDate.substr(0, 4));
    if (year < 2000 || year > currentYear) {
        return false;
    }
    int month = stoi(userDate.substr(5, 2));
    int day = stoi(userDate.substr(8));
    if (month > 12 || month < 1 || day < 1) {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    } else if (month == 2 && isALeapYear(userDate.substr(0, 4)) && day > 29) {
        return false;
    } else if (month == 2 && !isALeapYear(userDate.substr(0, 4)) && day > 28) {
        return false;
    }
    if (year == currentYear && month > currentMonth) {
        return false;
    }
    if (year == currentYear && month == currentMonth && day > currentDay) {
        return false;
    }
    return true;
}

int AuxiliaryFunctions::changeDateToInteger(string date) {
    return stoi(date.substr(0, 4) + date.substr(5, 2) + date.substr(8));
}
