class Solution {
public:
    vector<int> decode(vector<int> &encoded, int first) {
        vector<int> res;
        res.push_back(first);
        for (auto& x : encoded) {
            res.push_back(res.back() ^ x);
        }
        return res;
    }
};