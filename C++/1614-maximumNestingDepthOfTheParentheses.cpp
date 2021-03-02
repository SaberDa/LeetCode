class Solution {
public:
    int maxDepth(string s) {
        int d = 0, res = 0;
        for (auto c : s) {
            d += c == '(' ? 1 : c == ')' ? -1 : 0;
            res = max(res, d);
        }
        return res;
    }
};