#include <vector>
#include <queue>

using namespace std;

int maxEvents(vector<vector<int>> &events) {
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(events.begin(), events.end());
    int i = 0, res = 0, n = events.size();
    for (int d = 1; d <= 100000; d++) {
        while (pq.size() && pq.top() < d) pq.pop();
        while (i < n && events[i][0] == d) {
            pq.push(events[i][1]);
            i++;
        }
        if (pq.size()) {
            pq.pop();
            res++;
        }
    }
    return res;
}