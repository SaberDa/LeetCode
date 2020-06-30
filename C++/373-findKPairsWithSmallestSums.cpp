#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    auto comp = [](pair<int, int>& a, pair<int, int>& b){ return a.first + a.second < b.first + b.second;};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
    for (auto x : nums1) {
        for (auto y : nums2) {
            pq.push(make_pair(x, y));
            if (pq.size() > k) pq.pop();
        }
    }
    vector<vector<int>> res;
    while (!pq.empty()) {
        res.push_back({pq.top().first, pq.top().second});
        pq.pop();
    }
    return res;
}