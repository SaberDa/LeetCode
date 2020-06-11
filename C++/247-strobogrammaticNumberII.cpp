#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> helper(int m, int n) {
    if (m <= 0) return {""};
    if (m == 1) return {"0", "1", "8"};
    vector<string> v = helper(m - 2, n);
    vector<string> res;
    for (auto it : v) {
        if (m != n) res.push_back('0' + it +'0');
        res.push_back('1' + it + '1');
        res.push_back('6' + it + '9');
        res.push_back('8' + it + '8');
        res.push_back('9' + it + '6');
    }
    return res;
}

vector<string> findStrobogrammatic(int n) {
    return helper(n, n);
}