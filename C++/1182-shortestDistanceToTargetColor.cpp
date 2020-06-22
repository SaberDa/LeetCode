#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if  (nums[m] >= target) r = m - 1;
        else l = m + 1;
    }
    if (l == 0) return nums[l];
    else if (l == nums.size()) return nums[l - 1];
    else return (abs(target - nums[l]) < abs(target - nums[l - 1])) ? nums[l] : nums[l - 1];
}

vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
    vector<int> res;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < colors.size(); i++) mp[colors[i]].push_back(i);
    for (auto it : queries) {
        int index = it[0];
        int color = it[1];
        if (mp.count(color)) {
            int k = search(mp[color], index);
            res.push_back(abs(index - k));
        } else res.push_back(-1);
    }
    return res;
}