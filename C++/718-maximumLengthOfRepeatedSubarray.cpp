#include <iostream>
#include <vector>

using namespace std;

int findLength(vector<int>& A, vector<int>& B) {
    // dp[i][j] = (A[i] == B[j]) ? dp[i - 1][j - 1] + 1 : 0;
    int m = A.size(), n = B.size();
    vector<vector<int>> dp(m, vector<int>(n));
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) dp[i][j] = (A[i] == B[j]);
            else dp[i][j] = (A[i] == B[j]) ? dp[i - 1][j - 1] + 1 : 0;
            res = max(res, dp[i][j]);
        }
    }
    return res;
}