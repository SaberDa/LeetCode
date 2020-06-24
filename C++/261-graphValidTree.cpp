#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int find(vector<int>& parents, int c) {
    if (parents[c] != c) parents[c] = find(parents, parents[c]);
    return parents[c];
}

bool validTree(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;
    vector<int> parents(n);
    for (int i = 0; i < n; i++) parents[i] = i;
    for (auto edge : edges) {
        int root1 = find(parents, edge[0]);
        int root2 = find(parents, edge[1]);
        if (root1 == root2) return false;
        else parents[root1] = root2;
    }
    return true;
}