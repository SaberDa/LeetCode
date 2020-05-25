#include <isotream>
#include <string>
#include <vector>

using namespace std;

bool isInterval(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
        return false;
    }
    if (s1.empty()) {
        return s2 == s3;
    }
    if (s2.empty()) {
        return s1 == s3;
    }
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i > 0 && dp[i-1][j] && s1[i-1] == s3[i+j-1]) {
                dp[i][j] = 1;
            } else if (j > 0 && dp[i][j-1] && s2[j-1] == s3[i+j-1]) {
                dp[i][j] = 1;
            }
        }
    }
    return dp.back().back() == 1 ? true : false;
}