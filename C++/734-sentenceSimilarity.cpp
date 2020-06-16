#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
    if (words1.size() != words2.size()) return false;
    unordered_map<string, unordered_set<string>> mp;
    for (auto x : pairs) {
        mp[x[0]].insert(x[1]);
        mp[x[1]].insert(x[0]);
    }
    for (int i = 0; i < words1.size(); i++) {
        if (words1[i] != words2[i] && !mp[words1[i]].count(words2[i])) return false;
    }
    return true;
}