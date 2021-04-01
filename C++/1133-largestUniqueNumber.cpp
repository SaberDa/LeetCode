class Solution {
public:
    int largestUniqueNumber(vector<int> &A) {
        unordered_map<int, int> mp;
        int res = -1;
        for (auto c : A) mp[c]++;
        for (auto it : mp)
            if (it.second == 1 && it.first > res) res = it.first;
        return res;
    }
};