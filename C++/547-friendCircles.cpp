#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

int find(vector<int>& parents, int c) {
    return (parents[c] == c) ? parents[c] : find(parents, parents[c]);
}

int findCircleNum(vector<vector<int>>& M) {
    if (M.empty()) return 0;
    vector<int> parents(M.size());
    iota(parents.begin(), parents.end(), 0);
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[0].size(); j++) {
            if (M[i][j]) {
                int root1 = find(parents, i);
                int root2 = find(parents, j);
                if (root1 != root2) parents[root1] = root2;
                // parents[root1] = parents[root2];
            }
        }
    }
    unordered_set<int> st;
    for (int i = 0; i < parents.size(); i++) st.insert(find(parents, i));
    return st.size();
}