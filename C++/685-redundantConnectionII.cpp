#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int find(vector<int> &parent, int k) {
    return parent[k] == k ? parent[k] : find(parent, parent[k]);
}

vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> parent(n + 1, 0), res, temp;
    for (auto &edge : edges) {
        if (parent[edge[1]] == 0) {
            parent[edge[1]] = edge[0];
        } else {
            res = {parent[edge[1]], edge[1]};
            temp = edge;
            edge[1] = 0;
        }
    }
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (auto &edge : edges) {
        if (edge[1] == 0) continue;
        int root1 = find(parent, edge[0]);
        int root2 = find(parent, edge[1]);
        if (root1 == root2) {
            if (res.empty()) return edge;
            return res;
        }
        parent[root1] = root2;
    }
    return temp;
}