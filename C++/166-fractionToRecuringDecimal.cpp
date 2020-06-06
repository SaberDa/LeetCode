#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
        return "0";
    }
    string res;
    unordered_map<long long int, int> mp;
    bool flag = ((numerator <= 0 && denominator > 0) || (numerator > 0 && denominator <= 0));

    long long num = abs(numerator);
    long long den = abs(denominator);
    long long divided = num / den;
    long long rem = num % den;

    res = to_string(divided);
    if (rem == 0) {
        return flag ? '-' + res : res;
    }

    res.push_back('.');
    while (rem != 0) {
        num = rem * 10;
        if (mp.find(num) != mp.end()) {
            int pos = mp[num];
            res = res.substr(0, pos) + '(' + res.substr(pos) + ')';
            break;
        }
        mp[num] = res.size();
        divided = num / den;
        rem = num % den;
        res.push_back(divided + '0');
    }

    if (flag) {
        res.insert(res.begin(), '-');
    }
    return res;
}