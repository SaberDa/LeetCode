#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int reverse(int x) {
    int res = 0;
    while (x) {
        if (INT_MAX / 10 < res) {
            return 0;
        }
        if (INT_MIN / 10 > res) {
            return 0;
        }
        res = res * 10 + x % 10;
        x = x / 10;
    }
    return res;
}

// string::npos : the last of string
// stoi: convert string to int
// stol: convert string to long
// stoll: convert string to long long
// stof: convert string to float
// stod: convert string to double
// stold: convert string to long double
// stoul: convert string to unsigned long
int reverseInString(int x) {
    string temp = to_string(x);
    string res = "";
    if (temp.find("-") != string::npos) {
        res += "-";
    }
    for (int i = temp.length() - 1; i >= 0; i--) {
        // res += temp.substr(i, 1);
        res += temp.at(i);
    }
    if (stoll(res) > INT_MAX || stoll(res) < INT_MIN) {
        return 0;
    }
    return stoi(res);
}

int main() {
    int x = -123;
    cout << reverseInString(x) << endl;
    return 0;
}