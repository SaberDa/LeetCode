#include <iostream>
#include <string>

using namespace std;

string addStrings(string num1, string num2) {
    int sum(0), carry(0), x(0), y(0), remainder(0);
    string res;

    for (int i = num1.size() - 1, j = num2.size() - 1; (i >= 0) || (j >= 0); i--, j--) {
        x = (i >= 0) ? num1[i] - '0' : 0;
        y = (j >= 0) ? num2[j] - '0' : 0;

        int sum = x + y + carry;
        remainder = sum % 10;
        carry = sum / 10;

        res = (char)(remainder + '0') + res;  
    }

    return (carry == 1) ? ("1" + res) : res;
}