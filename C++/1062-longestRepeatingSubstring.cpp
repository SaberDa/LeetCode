#include <vector>
#include <string>

using namespace std;

int longestRepeatedSubstring(string S) {
    int res = 0, m = S.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (S[i] == S[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            res = max(res, dp[i + 1][j + 1]);
        }
    }
    return res;
}