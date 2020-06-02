#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

struct HashPair {
    template<class T1, class T2>
    size_t operator() (const pair<T1, T2>& p) const {
        auto h1 = hash<T1>()(p.first);
        auto h2 = hash<T2>()(p.second);
        return h1 ^ h2;
    }
};

int maxPoints(vector<vector<int>>& points) {
    if (points.empty()) {
        return 0;
    }
    unordered_map<pair<int, int>, int, HashPair> line_slope;
    int max_pts = 1;
    int dup = 0;
    int vertical = 0;
    for (int i = 0; i < points.size() - 1; i++) {
        dup = 0;
        vertical = 0;
        for (int j = i + 1; j < points.size(); j++) {
            if (points[i] == points[j]) {
                dup++;
            } else if (points[i][0] == points[j][0]) {
                vertical++;
            } else {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int gcd = GCD(x, y);
                pair<int, int> slope = make_pair(x / gcd, y / gcd);
                if (line_slope.count(slope) == 0) {
                    line_slope[slope] = 1;
                } else {
                    line_slope[slope]++;
                }
            }
        }
        for (auto it : line_slope) {
            max_pts = max(max_pts, it.second + dup + 1);
        }
        line_slope.clear();
        max_pts = max({max_pts, dup + 1, dup + vertical + 1});
    }
    return max_pts;
}