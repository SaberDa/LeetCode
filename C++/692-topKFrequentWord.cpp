#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    vector<string> res;
    if (words.empty() || k <= 0) return res;
    unordered_map<string, int> mp;
    for (auto x : words) mp[x]++;
    auto comp = [](pair<int, string>& a, pair<int, string>& b){return a.first == b.first ? a.second < b.second : a.first > b.first; };
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
    for(auto it : mp) {
        pq.push({it.second, it.first});
        if (pq.size() > k) pq.pop();
    }
    while (!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}