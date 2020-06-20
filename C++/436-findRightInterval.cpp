#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> findRightInterval(vector<vector<int>>& intervals) {
    if (intervals.empty()) return vector<int>();
    vector<int> res;
    map<int, int> mp;
    for (int i = 0; i < intervals.size(); i++) mp[intervals[i][0]] = i;
    for (auto x : intervals) {
        auto it = mp.lower_bound(x[1]);
        res.push_back((it == mp.end()) ? -1 : (*it).second);
    }
    return res;
}