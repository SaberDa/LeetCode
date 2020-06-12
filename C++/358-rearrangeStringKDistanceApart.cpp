#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

string rearrnageString(string s, int k) {
    if (k == 0) return s;
    string res = "";
    if (s.empty()) return res;
    unordered_map<char, int> dict;
    priority_queue<pair<int, char>> pq;
    int length = s.size();
    for (auto c : s) dict[c]++;
    for (auto it : dict) pq.push(make_pair(it.second, it.first));
    while (!pq.empty()) {
        vector<pair<int, char>> cache;
        int count = min(k, length);
        for (int i = 0; i < count; i++) {
            if (pq.empty()) return "";
            auto temp = pq.top();
            pq.pop();
            res.push_back(temp.second);
            if (--temp.first > 0) cache.push_back(temp);
            length--;
        }
        for (auto it : cache) pq.push(it);
    }
    return res;
}