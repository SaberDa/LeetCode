#include <iostream>
#include <vector>


using namespace std;

int find(vector<int>& parents, int c) {
    return (parents[c] == c) ? parents[c] : find(parents, parents[c]);
}

int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;
    vector<int> parents(n);
    iota(parents.begin(), parents.end(), 0);
    for (auto it : connections) {
        int root1 = find(parents, it[0]);
        int root2 = find(parents, it[1]);
        if (root1 != root2) {
            n--;
            parents[root1] = root2;
        }
    }
    return n - 1;
}