#include <iostream>
#include <ctime>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> mp;
public:
    Solution(vector<int>& nums) {
        srand(time(nullptr));
        for (int i(0); i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        return mp[target][rand() % mp[target].size()];
    }
};