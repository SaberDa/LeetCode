#include <iostream>
#include <vector>

using namespace std;

int cherryPickup(vector<vector<int>> &grid) {
    if (grid.empty()) return 0;
    int n = grid.size();
    int steps = 2 * (n - 1);
    vector<vector<int>> dp(n, vector<int>(n, -1));
    dp[0][0] = grid[0][0];
    for (int len = 1; len <= steps; len++) {
        vector<vector<int>> temp(n, vector<int>(n, -1));
        for (int i = 0; i <= len && i < n; i++) {
            if (len - i >= n) continue;
            for (int j = 0; j <= len && j < n; j++) {
                if (len - j >= n) continue;
                if (grid[i][len - i] < 0 || grid[j][len - j] < 0) continue;
                int num = dp[i][j];
                if (i > 0) num = max(num, dp[i - 1][j]);
                if (j > 0) num = max(num, dp[i][j - 1]);
                if (i > 0 && j > 0) num = max(num, dp[i - 1][j - 1]);
                if (num < 0) continue;
                num += grid[i][len - i] + (i == j ? 0 : grid[j][len - j]);
                temp[i][j] = num;
            }
        }
        dp = move(temp);
    }
    return max(dp.back().back(), 0);
}