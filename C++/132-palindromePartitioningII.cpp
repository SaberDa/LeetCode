#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minCut(string s) {
    int n = s.size();
    vector<vector<int>> valid(n, vector<int>(n, 1));
    vector<int> dp(n, n);
    for (int l = 2; l <= n; l++) {
        for (int i = 0, j = i + l - 1; j < n; i++, j++) {
            if (s[i] == s[j] && valid[i + 1][j - 1]) {
                valid[i][j] = 1;
            } else {
                valid[i][j] = 0;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (valid[0][i]) {
            dp[i] = 0;
            continue;
        }
        for (int j = 1; j <= i; j++) {
            if (valid[j][i]) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[n-1];
}