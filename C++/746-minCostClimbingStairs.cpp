#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    if (cost.empty()) return 0;
    vector<int> dp(cost.size(), 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    int res = min(dp[cost.size() - 1], dp[cost.size() - 2]);
    return res;
}