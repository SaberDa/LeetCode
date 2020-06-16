#include <iostream>
#include <vector>

using namespace std;

int DFS(vector<vector<int>>& path, vector<vector<int>>& dp, vector<vector<int>>& visited, int r, int c, int m, int n) {
    if (visited[r][c]) return 0;
    if (dp[r][c]) return dp[r][c];
    visited[r][c] = 1;
    int up = 1, down = 1, left = 1, right = 1;
    if (r - 1 >= 0 && path[r - 1][c] > path[r][c]) up = DFS(path, dp, visited, r - 1, c, m, n) + 1;
    if (r + 1 < m && path[r + 1][c] > path[r][c]) down = DFS(path, dp, visited, r + 1, c, m, n) + 1;
    if (c - 1 >= 0 && path[r][c - 1] > path[r][c]) left = DFS(path, dp, visited, r, c - 1, m, n) + 1;
    if (c + 1 < n && path[r][c + 1] > path[r][c]) right = DFS(path, dp,visited, r, c + 1, m, n) + 1;
    visited[r][c] = 0;
    dp[r][c] = max({up, down, left, right});
    return dp[r][c];
}

int longestIncreasingPath(vector<vector<int>>& path) {
    if (path.empty()) return 0;
    int m = path.size(), n = path[0].size();
    int len = 0;
    vector<vector<int>> dp(m, vector<int>(n));
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            len = max(len, DFS(path, dp, visited, i, j, m, n));
        }
    }
    return len;
}