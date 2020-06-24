#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parents, int c) {
    return (parents[c] == c) ? parents[c] : find(parents, parents[c]);
}

int removeStones(vector<vector<int>>& stones) {
    if (stones.empty()) return 0;
    vector<int> parents(stones.size() + 1);
    iota(parents.begin(), parents.end(), 0);
    for (int i = 0; i < stones.size(); i++) 
        for (int j = 0; j < i; j++)
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                int root1 = find(parents, i);
                int root2 = find(parents, j);
                if (root1 != root2) parents[root1] = root2;
            }
    int res = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (parents[i] == i) res++;
    }
    return stones.size() - res;
}