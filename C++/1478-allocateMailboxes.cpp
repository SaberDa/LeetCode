class Solution {
public:

    int dp[101][101][101] = {};

    int DFS(vector<int> &house, int i, int j, int k) {
        if (i >= house.size() || k <= 0) {
            return i == house.size() && k == 0 ? 0 : INT_MAX;
        }
        if (dp[i][j][k]) return dp[i][j][k];
        dp[i][j][k] = DFS(house, i + 1, i + 1, k - 1);
        if (dp[i][j][k] != INT_MAX) {
            for (auto p = j; p <= i; p++) {
                dp[i][j][k] += abs(house[(i + j) / 2] - house[p]);
            }
        }
        return dp[i][j][k] = min(dp[i][j][k], DFS(house, i + 1, j, k));
    }

    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        return DFS(houses, 0, 0, k);
    }
};