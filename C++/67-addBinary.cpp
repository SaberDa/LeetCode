#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    string res = "";
    while (i >= 0 || j >= 0 || carry) {
        int iRes = i >= 0 ? (a[i] - '0') : 0;
        int jRes = j >= 0 ? (b[j] - '0') : 0;
        int sum = iRes + jRes + carry;
        carry = sum / 2;
        res = char((sum % 2) + '0') + res;
        if (i >= 0) {
            i--;
        }
        if (j >= 0) {
            j--;
        }
    }
    return res;
}

int main() {
    cout << addBinary("1010", "1011");
    return 0;
}