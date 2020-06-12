#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int numberOfBoomerangs(vector<vector<int>>& points) {
    int res = 0;
    if (points.empty()) return 0;
    unordered_map<long, int> mp;
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
            if (j == i) continue;
            int x = points[i][0] - points[j][0];
            int y = points[i][1] - points[j][1];
            long key = pow(x, 2) + pow(y, 2);
            mp[key]++;
        }
        for (auto it : mp) {
            // Select 2 from n : n*(n-1)
            if (it.second > 1) res += it.second * (it.second - 1);
        }
        mp.clear();
    }
    return res;
}