#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDistinct(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<long int>> dp(n + 1, vector<long int>(m + 1, 0));
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            long int temp = 0;
            if (t[j - 1] == s[i - 1]) {
                temp = dp[j - 1][i - 1];
            }
            dp[j][i] = dp[j][i - 1] + temp;
        }
    }
    return dp.back().back();
}