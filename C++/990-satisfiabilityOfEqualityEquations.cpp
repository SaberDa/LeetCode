#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parents, int c) {
    return (parents[c] == c) ? parents[c] : find(parents, parents[c]);
}

bool equationsPossible(vector<string>& equations) {
    if (equations.empty()) return false;
    vector<int> parents(26);
    iota(parents.begin(), parents.end(), 0);
    for (auto s : equations) {
        if (s[1] == '=') {
            int root1 = find(parents, s[0] - 'a');
            int root2 = find(parents, s[3] - 'a');
            if (root1 != root2) parents[root1] = root2; 
        }
    }
    for (auto s : equations) {
        if (s[1] == '!' && find(parents, s[0] - 'a') == find(parents, s[3] - 'a')) return false; 
    }
    return true;
}