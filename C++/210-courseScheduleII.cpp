#include <iostream>
#include <vector>

using namespace std;

vector<int> findOrder(int n, vector<vector<int>>& p) {
    vector<int> res;
    vector<int> in(n);
    vector<vector<int>> graph(n);
    for (int i = 0; i < p.size(); i++) {
        graph[p[i][1]].push_back(p[i][0]);
        in[p[i][0]]++;
    }
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (; j < n; j++) {
            if (in[j] == 0) break;
        }
        if (j == n) return vector<int>();
        in[j] = -1;
        for (auto x : graph[j]) in[x]--;
        res.push_back(j);
    }
    return res;
} 