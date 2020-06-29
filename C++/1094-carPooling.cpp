#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    map<int, int> mp;
    for (auto x : trips) {
        mp[x[1]] += x[0];
        mp[x[2]] -= x[0];
    }
    int count = 0;
    for (auto it : mp) {
        count += it.second;
        if (count > capacity) return false;
    }
    return 0;
}
