#include <iostream>
#include <vector>

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    if (dungeon.empty()) {
        return 1;
    }
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n - 1] = 1;
    int hp = 0;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            hp = min(dp[j], dp[j+1]) - dungeon[i][j];
            dp[j] = max(hp, 1);
        }
    }
    return dp[0];
}