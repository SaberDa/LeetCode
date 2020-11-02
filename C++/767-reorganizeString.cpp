#include <string>
#include <queue>
#include <vector>

using namespace std;

string reorganizeString(string S) {
    vector<int> mp(26);
    for (auto c : S) mp[c - 'a']++;
    int n = S.size();
    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; i++) {
        if (mp[i] > (n + 1) / 2) return "";
        if (mp[i]) pq.push({mp[i], i + 'a'});
    }
    queue<pair<int, char>> myq;
    string res = "";
    while (!pq.empty() || myq.size() > 1) {
        if (myq.size() > 1) {
            auto cur = myq.front();
            myq.pop();
            if (cur.first != 0) pq.push(cur);
        }
        if (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            res += cur.second;
            cur.first--;
            myq.push(cur);
        }
    }
    return res;
}