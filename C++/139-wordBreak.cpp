#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    if (s.empty() || wordDict.size() == 0) {
        return false;
    }
    int n = s.length();
    vector<bool> dp(n+1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (auto k : wordDict) {
            int curIndex = i - k.size();
            if (curIndex < 0 || dp[curIndex] == false) {
                continue;
            }
            if (k == s.substr(curIndex, k.size())) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}