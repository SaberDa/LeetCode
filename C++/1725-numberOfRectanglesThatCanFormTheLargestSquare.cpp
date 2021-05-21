class Solution {
public:
    int countGoodRectangles(vector<vector<int>> &rectangles) {
        unordered_map<int, int> mp;
        int res = 0;
        for (auto x : rectangles) {
            int minV = min(x[0], x[1]);
            mp[minV]++;
            res = max(res, minV);
        }
        return mp[res];
    }
};