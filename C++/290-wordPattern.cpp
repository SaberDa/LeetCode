#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string str) {
    if (pattern.empty() && str.empty()) return true;
    if (pattern.empty() || str.empty()) return false;
    unordered_map<char, string> c2s;
    unordered_map<string, char> s2c;
    string s = "";
    int i = 0;
    stringstream ss(str);
    while (ss>>s) {
        if (i == pattern.size() || (s2c.count(s) && s2c[s] != pattern[i]) || (c2s.count(pattern[i]) && c2s[pattern[i]] != s)) return false;
        s2c[s] = pattern[i];
        c2s[pattern[i]] = s;
        i++;
    }
    return i == pattern.size();
}