class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points) {
        int res = 0;
        if (points.empty() || points.size() == 1) return 0;
        for (int i = 1; i < points.size(); i++) {
            int x = abs(points[i][0] - points[i - 1][0]);
            int y = abs(points[i][1] - points[i - 1][1]);
            res += max(x, y);
        }
        return res;
    }
};