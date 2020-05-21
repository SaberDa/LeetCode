#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long toInt(string num) {
    vector<long> res;
    for (auto str : num) {
        res.push_back(str - '0');
    }
    long nums = 0;
    for (int i = 0; i < res.size(); i++) {
        nums = nums * 10 + res[i];
    }
    return nums;
}

string toStr(long num) {
    string res = "";
    while (num) {
        int temp = num % 10;
        res += (temp + '0');
        num = num / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string multiply(string num1, string num2) {
    vector<int> pos(num1.size() + num2.size());
    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            int sum = (num1[i] - '0') * (num2[j] - '0') + pos[i + j + 1];
            pos[i + j + 1] = sum % 10;
            pos[i + j] += sum / 10;
        }
    }
    string res = "";
    for (auto it : pos) {
        if (!(res == "" && it == 0)) {
            res.push_back(it + '0');
        }
    }
    return res == "" ? "0" : res;
}

int main() {
    cout << toInt("123") << endl;
    cout << toStr(1234) << endl;
    return 0;
}