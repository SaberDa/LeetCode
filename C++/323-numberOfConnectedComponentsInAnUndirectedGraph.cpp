#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int find(vector<int>& parents, int c) {
    if (parents[c] != c) parents[c] = find(parents, parents[c]);
    return parents[c];
}

int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> parents(n);
    iota(parents.begin(), parents.end(), 0);
    for (auto edge : edges) {
        int root1 = find(parents, edge[0]);
        int root2 = find(parents, edge[1]);
        parents[root1] = root2;
        if (root1 != root2) n--;
    }
    return n;
}