#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    backtrack(res, vector<string>(), 0, s);
    return res;
}

void backtrack(vector<vector<string>>& res, vector<string> temp, int pos, string s) {
    if (pos >= s.size()) {
        res.push_back(temp);
        return;
    }
    temp.push_back(s.substr(pos, 1));
    backtrack(res, temp, pos + 1, s);
    temp.pop_back();

    for (int i = 2; i + pos <= s.size(); i++) {
        if (isPalindrome(s.substr(pos, i))) {
            temp.push_back(s.substr(pos, i));
            backtrack(res, temp, pos + i, s);
            temp.pop_back();
        }
    }
}

bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
} 