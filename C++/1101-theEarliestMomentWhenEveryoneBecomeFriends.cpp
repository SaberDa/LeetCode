#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parents, int c) {
    return (parents[c] == c) ? parents[c] : find(parents, parents[c]);
}

int earliestAcq(vector<vector<int>>& logs, int N) {
    sort(logs.begin(), logs.end());
    vector<int> parents(N);
    iota(parents.begin(), parents.end(), 0);
    for (int i = 0; i < logs.size(); i++) {
        int root1 = find(parents, logs[i][1]);
        int root2 = find(parents, logs[i][2]);
        if (root1 != root2) {
            if (--N == 1) return logs[i][0];
            parents[root1] = root2;
        }
    }
    return 0;
}