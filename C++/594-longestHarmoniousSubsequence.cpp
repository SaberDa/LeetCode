#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findLHS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int len = 0;
    unordered_map<int, int> mp;
    for (auto x : nums) mp[x]++;
    for (auto it : mp) {
        int y = it.first;
        if (mp.count(y + 1)) len = max(len, it.second + mp[y + 1]);
    }
    return len;
}