#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addStrings(string num1, string num2) {
    int carry = 0;
    string res = "";
    for (int i = num1.size() - 1, j = num2.size(); i >= 0 || j >= 0; i--, j--) {
        int x = (i >= 0) ? num1[i] - '0' : 0;
        int y = (j >= 0) ? num2[j] - '0' : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        int remainder = sum % 10;
        res = (char)(remainder + '0') + res;
    }
    return carry == 1 ? "1" + res : res;
}