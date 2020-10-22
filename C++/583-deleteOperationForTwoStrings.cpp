#include <vector>
#include <string>

using namespace std;

int minDistance(string word1, string word2) {
    if (word1.empty()) return word2.size();
    if (word2.empty()) return word1.size();
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (!i || !j) {
                dp[i][j] = 0;
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int temp = dp[m][n];
    return (word1.size() - temp) + (word2.size() - temp);
}