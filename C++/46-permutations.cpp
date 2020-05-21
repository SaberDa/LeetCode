#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    DFS(nums, res, 0);
    return res;
}

void DFS(vector<int>& nums, vector<vector<int>>& res, int pos) {
    if (pos == nums.size() - 1) {
        res.push_back(nums);
        return;
    }
    for (int i = pos; i < nums.size(); i++) {
        swap(nums[i], nums[pos]);
        DFS(nums, res, pos + 1);
        swap(nums[i], nums[pos]);
    }
}