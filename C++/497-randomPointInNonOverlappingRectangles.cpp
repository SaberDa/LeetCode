#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> r;
    vector<int> area;

    int helper(vector<int>& nums) {
        return (nums[2] - nums[0] + 1) * (nums[3] - nums[1] + 1);
    }

    Solution(vector<vector<int>>& rects) {
        r = rects;
        for (auto& it : rects) {
            area.push_back(helper(it) + (area.empty() ? 0 : area.back()));
        }
    }

    vector<int> pick() {
        auto it = upper_bound(area.begin(), area.end(), rand() % area.back());
        int idx = it - area.begin();
        return {rand() % (r[idx][2] - r[idx][0] + 1) + r[idx][0], rand() % (r[idx][3] - r[idx][1] + 1) + r[idx][1]};
    }
};