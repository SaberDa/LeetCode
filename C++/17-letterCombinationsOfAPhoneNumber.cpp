#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) {
        return res;
    }
    vector<string> dict({{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}});
    string temp = "";
    DFS(digits, dict, res, temp, 0);
    return res;
}

void DFS(string digits, vector<string>& dict, vector<string>& res, string temp, int pos) {
    if (pos == digits.length()) {
        res.push_back(temp);
        return;
    }
    for (auto c : dict[digits[pos] - '0']) {
        temp.push_back(c);
        DFS(digits, dict, res, temp, pos+1);
        temp.pop_back();
    }
}