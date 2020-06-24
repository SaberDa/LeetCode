#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parents, int c) {
    return (parents[c] == c) ? parents[c] : find(parents, parents[c]);
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    if (edges.empty()) return vector<int>();
    vector<int> parents(edges.size() + 1);
    iota(parents.begin(), parents.end(), 0);
    for (auto edge : edges) {
        int root1 = find(parents, edge[0]);
        int root2 = find(parents, edge[1]);
        if (root1 == root2) return edge;
        else parents[root1] = root2;
    }
    return edges[0];
}