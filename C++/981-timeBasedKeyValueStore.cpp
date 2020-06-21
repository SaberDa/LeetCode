#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    TimeMap () {};

    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        auto& it = mp[key];
        int l = 0, r = (int)it.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (it[m].second > timestamp) r = m - 1;
            else l = m + 1;
        }
        return (r < 0) ? "" : it[r].first;
    }
};