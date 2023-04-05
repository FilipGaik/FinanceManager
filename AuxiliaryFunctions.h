#ifndef AUXILIARYFUNCTIONS_H
#define AUXILIARYFUNCTIONS_H

#include <iostream>
#include <ctime>

using namespace std;

class AuxiliaryFunctions {
public:
    static string readLine();
    static bool isNumber(string line);
    static string getTodaysDate();
    static bool checkDate(string userDate);
    static bool isALeapYear(string year);
    static int changeDateToInteger(string date);
};

#endif
