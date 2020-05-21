#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.empty()) {
        return res;
    }
    DFS(nums, res, 0);
    return res;
}

void DFS(vector<int>& nums, vector<vector<int>>& res, int pos) {
    if (pos == nums.size() - 1) {
        res.push_back(nums);
        return;
    }
    unordered_set<int> swapped;
    for (int i = pos; i < nums.size(); i++) {
        if (swapped.find(nums[i]) != swapped.end()) {
            continue;
        }
        swapped.insert(nums[i]);
        swap(nums[pos], nums[i]);
        DFS(nums, res, pos + 1);
        swap(nums[pos], nums[i]);
    }
}