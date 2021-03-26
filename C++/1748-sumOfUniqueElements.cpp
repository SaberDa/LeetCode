class Solution {
public:
    int sumOfUnique(vector<int> &nums) {
        unordered_map<int, int> mp;
        int res = 0;
        for (auto x : nums) mp[x]++;
        for (auto it : mp) if (it.second == 1) res += it.first;
        return res;
    }
};