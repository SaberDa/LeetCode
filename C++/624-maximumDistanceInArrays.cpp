#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxDistance(vector<vector<int>>& nums) {
    int res = 0;
    int left = nums[0][0], right = nums[0].back();
    for (int i = 1; i < nums.size(); i++) {
        res = max(res, max(abs(nums[i][0] - right), abs(nums[i].back() - left)));
        left = min(left, nums[i][0]);
        right = max(right, nums[i].back());
    }
    return res;
}