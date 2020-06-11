#include <iostream>
#include <unordered_map>

using namespace std;

bool isStrobogrammatic(string num) {
    string s = "";
    if (num.empty()) return false;
    unordered_map<char, char> mp{{'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}, {'0', '0'}};
    for (auto c : num) {
        if (!mp.count(c)) return false;
        s.push_back(mp[c]);
    }
    reverse(s.begin(), s.end());
    return s == num;
}