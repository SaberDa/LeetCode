#include <iostream>
#include <string>

using namespace std;

int reverse(int x) {
    string temp = to_string(x);
    string res = "";
    if (temp.find("-") != string::npos) res += "-";
    for (int i = temp.size() - 1; i >= 0; i--) res += temp[i];
    if (stoll(res) > INT_MAX || stoll(res) < INT_MIN) return 0;
    return stoi(res);
}