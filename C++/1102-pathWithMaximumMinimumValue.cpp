#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vextex {
    int i, j, val;
    bool operator<(const Vextex& a) const {return val < a.val;}     // Maxheap
};

vector<pair<int, int>> d = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int maximumMinimumPath(vector<vector<int>>& A) {
    if (A.empty()) return 0;
    int m = A.size(), n = A[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    priority_queue<Vextex> pq;
    pq.push({0, 0, A[0][0]});
    while (!pq.empty()) {
        const auto [i, j, val] = pq.top();
        pq.pop();
        if (i == m - 1 && j == n - 1) return val;
        dp[i][j] = val;
        for (auto [dx, dy] : d) {
            int x = i + dx, y = j + dy;
            if (x < 0 || y < 0 || x == m || y == n || dp[x][y] != -1) continue;
            dp[x][y] = min(val, A[x][y]);
            pq.push({x, y, dp[x][y]});
        }
    }
    return -1;
}