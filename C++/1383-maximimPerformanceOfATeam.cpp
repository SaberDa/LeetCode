#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
    vector<pair<int, int>> ess;
    for (int i = 0; i < speed.size(); i++) {
        ess.push_back(make_pair(efficiency[i], speed[i]));
    }
    sort(ess.rbegin(), ess.rend());
    long sum = 0, res = 0;
    long p = 1e9 + 7;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto x : ess) {
        pq.push(x.second);
        sum += x.second;
        if (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        res = max(res, x.first * sum);
    }
    return res % (int)p;
}