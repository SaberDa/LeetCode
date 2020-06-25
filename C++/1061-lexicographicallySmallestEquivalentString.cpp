#include <iostream>
#include <vector>
#include <string>

using namespace std;

int find(vector<int>& parents, int c) {
    return (parents[c] == c) ? parents[c] : find(parents, parents[c]);
}

string smallestEquivalentString(string A, string B, string S) {
    vector<int> parents(26);
    iota(parents.begin(), parents.end(), 0);
    for (int i = 0; i < A.size(); i++) {
        int root1 = find(parents, A[i] - 'a');
        int root2 = find(parents, B[i] - 'a');
        if (root1 != root2) parents[max(root1, root2)] = min(root1, root2);
    }
    for (int i = 0; i < S.size(); i++) {
        S[i] = find(parents, S[i] - 'a') + 'a';
    }
    return S;
}