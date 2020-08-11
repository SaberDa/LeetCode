#include <iostream>
#include <vector>

using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size(), sum = 0, maxRight = 0, maxSum = 0, idx = 0;
    vector<int> res, dp(n - k + 1), nextMax(n - k + 1), nextIdx(n - k + 1);
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (i >= k) sum -= nums[i - k];
        if (i >= k - 1) dp[i - k + 1] = sum;
    }
    for (int i = dp.size() - 1; i >= 0; i--) {
        if (dp[i] > maxRight) maxRight = dp[i], idx = i;
        nextMax[i] = maxRight;
        nextIdx[i] = idx;
    }
    for (int i = 0; i <= n - 3 * k; i++) {
        for (int j = i + k; j <= n - 2 * k; j++) {
            sum = dp[i] + dp[j] + nextMax[j + k];
            if (sum > maxSum) {
                maxSum = sum;
                res = {i, j, nextIdx[j + k]};
            }
        }
    }
    return res;
}