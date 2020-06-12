#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

bool isReflected(vector<vector<int>>&& points) {
    unordered_map<int, set<int>> mp;
    if (points.empty()) return false;
    int m = INT_MIN, n = INT_MAX;
    for (auto x : points) {
        m = max(m, x[0]);
        n = min(n, x[0]);
        mp[x[0]].insert(x[1]);
    }
    double y = (double)(m + n) / 2;
    for (auto x : points) {
        int t = 2 * y - x[0];
        if (!mp.count(t) || !mp[t].count(x[1])) return false;
    }
    return true;
}