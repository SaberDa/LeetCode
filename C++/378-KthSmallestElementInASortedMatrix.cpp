#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    if (matrix.empty()) return 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (auto x : matrix)
        for (auto y : x) pq.push(y);
    while (--k) pq.pop();
    return pq.top();
}