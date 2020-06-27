#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void DFS(string cur, vector<string>& res, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& mp) {
    while (!mp[cur].empty()) {
        string s = mp[cur].top();
        mp[cur].pop();
        DFS(s, res, mp);
    }
    res.push_back(cur);
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;
    vector<string> res;
    for (auto x : tickets) mp[x[0]].push(x[1]);
    DFS("JFK", res, mp);
    reverse(res.begin(), res.end());
    return res;
}

