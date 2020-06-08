#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    int x = 0, y = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i & 1) {
            x = max(nums[i] + x, y);
        } else {
            y = max(nums[i] + y, x);
        }
    }
    return max(x, y);
}

int rob(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    vector<int> first(nums.begin() + 1, nums.end());
    vector<int> second(nums.begin(), nums.end() - 1);
    return max(helper(first), helper(second));
}