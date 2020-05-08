#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> mp;

    for (auto& s: strings) {
        mp[shift(s)].push_back(s);
    }

    for (auto& v : mp) {
        sort(v.second.begin(), v.second.end());
        res.push_back(v.second);
    }
    
    return res;
}

string shift(string s) {
    if (s.size() <= 1) {
        return "a";
    }
    int diff = s[0] - 'a';
    string res;
    for (auto c : s) {
        if (c - diff < 'a') {
            c += (26 - diff);
        } else {
            c -= diff;
        }
        res.push_back(c);
    }
    return res;
}



int main() {

    vector<string> strings;
    strings.push_back("abc");
    strings.push_back("bcd");
    strings.push_back("acef");
    strings.push_back("xyz");
    strings.push_back("az");
    strings.push_back("ba");
    strings.push_back("a");
    strings.push_back("z");

    cout << shift(strings[0]) << endl;
    return 0;
}