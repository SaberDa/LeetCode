#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> dp(nums.size(), 1);
    dp[0] = 1;
    int res = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] < nums[i]) {
            dp[i] = max(dp[i], dp[i - 1] + 1);
            res = max(res, dp[i]);
        }
    }
    return res;
}