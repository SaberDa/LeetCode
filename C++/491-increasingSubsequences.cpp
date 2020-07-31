#include <iostream>
#include <vector>
#include <set>

using namespace std;

void helper(vector<int>& nums, set<vector<int>>& res, vector<int>& temp, int pos, int cur) {
    if (pos == nums.size()) return;
    if (temp.size() > 1) res.insert(temp);
    for (int i = pos + 1; i < nums.size(); i++) {
        if (nums[i] >= cur) {
            temp.push_back(nums[i]);
            helper(nums, res, temp, i, nums[i]);
            temp.pop_back();
        }
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    set<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
        vector<int> temp;
        temp.push_back(nums[i]);
        helper(nums, res, temp, i, nums[i]);
    }
    return vector<vector<int>>(res.begin(), res.end());
}