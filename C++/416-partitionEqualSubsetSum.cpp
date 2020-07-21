#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    int size = nums.size();
    vector<vector<bool>> dp(size, vector<bool>(sum / 2 + 1, false));
    dp[0][0] = true;
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < sum / 2 + 1; j++) {
            dp[i][j] = dp[i - 1][j] || ((j >= nums[i]) ? dp[i - 1][j - nums[i]] : 0);
        }
    }
    return dp.back().back();
}