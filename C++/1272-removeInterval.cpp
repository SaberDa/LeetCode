class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int> &toBeRemoved) {
        vector<vector<int>> res;
        int start = toBeRemoved[0], end = toBeRemoved[1];
        for (auto x : intervals) {
            if (x[1] <= start || x[0] >= end) res.push_back(x);
            else {
                if (x[0] < start) res.push_back({x[0], start});
                if (x[1] > end) res.push_back({end, x[1]});
            }
        }
        return res;
    }
};