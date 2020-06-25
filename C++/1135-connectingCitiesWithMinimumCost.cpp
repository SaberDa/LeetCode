#include <isotream>
#include <vector>

using namespace std;

int find(vector<int>& parents, int c) {
    return parents[c] == c ? parents[c] : find(parents, parents[c]);
}

int minimumCost(int N, vector<vector<int>>& connections) {
    int res = 0;
    vector<int> parents(N + 1);
    iota(parents.begin(), parents.end(), 0);
    auto comp = [](vector<int>& a, vector<int>& b){return a[2] < b[2];};
    sort(connections.begin(), connections.end(), comp);
    for (auto it : connections) {
        int root1 = find(parents, it[0]);
        int root2 = find(parents, it[1]);
        if (root1 != root2) {
            res += it[2];
            parents[root1] = root2;
            N--;
        }
    }
    return N == 1 ? res : -1;
}