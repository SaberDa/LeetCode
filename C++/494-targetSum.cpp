#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int>& nums, int S, int pos, int sum, int& res) {
    if (pos == nums.size()) {
        if (sum == S) res++;
        return;
    }
    helper(nums, S, pos + 1, sum + nums[pos], res);
    helper(nums, S, pos + 1, sum - nums[pos], res);
}

int findTargetSumWays(vector<int>& nums, int S) {
    int res = 0;
    helper(nums, S, 0, 0, res);
    return res;
}