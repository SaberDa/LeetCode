#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string find(unordered_map<string, string>& parents, string str) {
    return (parents[str] == str) ? parents[str] : find(parents, parents[str]);
}

bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
    if (words1.size() != words2.size()) return false;
    unordered_map<string, string> parents;
    for (int i = 0; i < pairs.size(); i++) {
        if (!parents.count(pairs[i][0])) parents[pairs[i][0]] = pairs[i][0];
        if (!parents.count(pairs[i][1])) parents[pairs[i][1]] = pairs[i][1];
        string root1 = find(parents, pairs[i][0]);
        string root2 = find(parents, pairs[i][1]);
        if (root1 != root2) parents[root1] = root2;
    }
    for (int i = 0; i < words1.size(); i++) {
        if (find(parents, words1[i]) != find(parents, words2[i])) return false;
    }
    return true;
}