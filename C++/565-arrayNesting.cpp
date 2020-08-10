#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<int>& nums, int num, int depth, int& res) {
    if (nums[num] == -1) {
        res = max(res, depth);
        return;
    }
    int next = nums[num];
    nums[num] = -1;
    DFS(nums, next, depth + 1, res);
}

int arrayNesting(vector<int>& nums) {
    if (nums.empty()) return 0;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == -1) continue;
        DFS(nums, nums[i], 0, res);
    }
    return res;
}