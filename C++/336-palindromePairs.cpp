#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_map<string, int> dict;
    vector<vector<int>> res;
    if (words.empty()) return res;
    for (int i = 0; i < words.size(); i++) {
        string s = words[i];
        reverse(s.begin(), s.end());
        dict[s] = i;
    }
    if (dict.count("")) {
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == "") continue;
            if (isPalindrome(words[i])) res.push_back({dict[""], i});
        }
    }
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
            string left = words[i].substr(0, j);
            string right = words[i].substr(j);
            if (dict.count(left) && isPalindrome(right) && i != dict[left]) res.push_back({i, dict[left]});
            if (dict.count(right) && isPalindrome(left) && i != dict[right]) res.push_back({dict[right], i});
        }
    }
    return res;
}

