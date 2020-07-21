#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (auto x : slots1) {
        if (x[1] - x[0] >= duration) q.push({x[0], x[1]});
    }
    for (auto x : slots2) {
        if (x[1] - x[0] >= duration) q.push({x[0], x[1]});
    }
    while (q.size() > 1) {
        auto end = q.top();
        q.pop();
        auto start = q.top();
        if (end.second - start.first >= duration) {
            return {start.first, start.first + duration};
        }
    }
    return {};
}