class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
        int res = -1, minDis = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            if (x == points[i][0] || y == points[i][1]) {
                int cur = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (cur < minDis) {
                    minDis = cur;
                    res = i;
                }
            }
        }
        return res;
    }
};