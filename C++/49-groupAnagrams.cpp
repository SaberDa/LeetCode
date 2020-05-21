#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    if (strs.empty()) {
        return res;
    }
    unordered_map<string, vector<string>> mp;
    for (auto str : strs) {
        string temp = str;
        sort(temp.begin(), temp.end());
        mp[temp].push_back(str);
    }
    for (auto it : mp) {
        res.push_back(it.second);
    }
    return res;
}