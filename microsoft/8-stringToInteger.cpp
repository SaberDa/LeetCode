#include <iostream>
#include <string>
#include <climits>

using namespace std;

int myAtoi(string str) {
    int size = str.size();
    long num = 0;
    bool isNeg;

    int i = 0;
    while (i < size && str[i] == ' ') i++;
    if (i < size && str[i] == '-') i++, isNeg = true;
    else if (i < size && str[i] == '+') i++, isNeg = false;

    while (i < size && (str[i] >= '0' && str[i] <= '9')) {
        num = num * 10 + (str[i] - '0');
        if (num > INT_MAX) break;
        i++;
    }

    if (num > INT_MAX) {
        if (isNeg) return INT_MIN;
        else return INT_MAX;
    }

    if (isNeg) return num * -1;
    else return num;
}