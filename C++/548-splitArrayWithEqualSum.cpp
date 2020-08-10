#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool dfs(vector<int>& nums, vector<int>& sum, unordered_map<int, unordered_set<int>>& mp, int total, int i, int pos) {
    if (pos == 4 && i == nums.size()) return true;
    if (pos > 4) return false;
    for (int j = i + 1; j < nums.size(); j++) {
        if (sum[j] - sum[i] == total) {
            if (mp.count(j) && mp[j].count(total)) continue;
            if (dfs(nums, sum, mp, total, j + 1, pos + 1)) return true;
            mp[j].insert(total);
        }
    }
    return false;
}

bool splitArray(vector<int>& nums) {
    if (nums.size() < 7) return false;
    vector<int> sum(nums.size(), 0);
    unordered_map<int, unordered_set<int>> mp;
    sum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        sum[i] = sum[i - 1] + nums[i];
    }
    for (int i = 0; i < nums.size(); i++) {
        int total = sum[i];
        if (mp.count(i) && mp[i].count(total)) continue;
        if (dfs(nums, sum, mp, total, i + 1, 1)) return true;
        mp[i].insert(total);
    }
    return false;
}