class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, temp = res;
        for (auto x : gain) {
            temp += x;
            res = max(res, temp);
        }
        return res;
    }
};