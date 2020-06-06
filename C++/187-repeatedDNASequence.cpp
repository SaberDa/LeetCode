#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    if (s.empty()) {
        return res;
    }
    unordered_map<string, int> mp;
    for (int i = 0; i + 10 <= s.size(); i++) {
        string temp = s.substr(i, 10);
        if (mp[temp] == 1) {
            res.push_back(temp);
        }
        mp[temp]++;
    }
    return res;
}