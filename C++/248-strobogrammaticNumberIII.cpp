#include <iostream>
#include <string>

using namespace std;

bool compare(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return s1.size() < s2.size();
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] < s2[i]) return true;
        else if (s1[i] > s2[i]) return false;
    }
    return true;
}

void helper(int& res, const string& low, const string& high, string temp) {
    if (!compare(temp, high)) return;
    if (compare(low, temp) && compare(temp, high)) {
        if ((temp.size() == 1) || (temp.size() > 1 && temp[0] != '0')) res++;
    }
    helper(res, low, high, '0' + temp + '0');
    helper(res, low, high, '1' + temp + '1');
    helper(res, low, high, '6' + temp + '9');
    helper(res, low, high, '8' + temp + '8');
    helper(res, low, high, '9' + temp + '6');
}

int strobogrammaticInRange(string low, string high) {
    if (!compare(low, high)) return 0;
    int res = 0;
    helper(res, low, high, "");
    helper(res, low, high, "0");
    helper(res, low, high, "1");
    helper(res, low, high, "8");
    return res;
}