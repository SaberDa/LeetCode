#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int leastBricks(vector<vector<int>>& wall) {
    if (wall.empty()) return 0;
    unordered_map<int, int> mp;
    int res = wall.size();
    int n = res;
    for (auto x : wall) {
        int len = 0;
        // expect the edge, so the range is from 0 to size()-1
        for (int i = 0; i < x.size() - 1; i++) {
            len += x[i];
            mp[len]++;
        }
    }
    for (auto it : mp) res = min(res, n - it.second);
    return res;
}