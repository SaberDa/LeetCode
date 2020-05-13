#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void DFS(vector<unordered_set<int>> &dp, vector<string>& res, int n, string& s) {
    if (n < s.size()) {
        s.insert(n, 1, ' ');
    }

    for (auto temp : dp[n]) {
        if (temp == 0) {
            res.push_back(s);
        } else {
            DFS(dp, res, temp, s);
        }
    }

    if (n < s.size()) {
        s.erase(n, 1);
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<int> lens;
    unordered_set<string> word;
    for (auto k : wordDict) {
        lens.insert(k.length());
        word.insert(k);
    }
    int n = s.length();
    vector<unordered_set<int>> dp(n+1, unordered_set<int>());
    for (int i = 1; i <= n; i++) {
        for (auto l : lens) {
            if (l <= i) {
                string temp(s.begin() + i - l, s.begin() + i);
                if (word.count(temp)) {
                    if (i == l || !dp[i-l].empty()) {
                        dp[i].insert(i-l);
                    }
                }
            }
        }
    }

    vector<string> res;
    DFS(dp, res, n, s);
    return res;
}