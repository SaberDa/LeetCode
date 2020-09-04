#include <vector>
#include <unordered_map>

using namespace std;

vector<int> partitionLabels(string S) {
    vector<int> res;
    if (S.empty()) return res;
    unordered_map<char, int> mp;
    for (int i = 0; i < S.size(); i++) mp[S[i]] = i;
    int start = 0, end = 0;
    for (int i = 0; i < S.size(); i++) {
        end = max(end, mp[S[i]]);
        if (end == i) {
            res.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return res;
}