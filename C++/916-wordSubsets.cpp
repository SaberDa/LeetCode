#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> helper(string s) {
    vector<int> res(26);
    for (auto c : s) res[c - 'a']++;
    return res;
}

vector<string> wordSubsets(vector<string> &A, vector<string> &B) {
    vector<string> res;
    if (A.empty() || B.empty()) return res;
    vector<int> count(26), temp(26);
    for (auto s : B) {
        temp = helper(s);
        for (int i = 0; i < 26; i++) {
            count[i] = max(count[i], temp[i]);
        }
    }
    for (auto s : A) {
        temp = helper(s);
        int i = 0;
        while (i < 26) {
            if (temp[i] < count[i]) break;
            i++;
        }
        if (i == 26) res.push_back(s);
    }
    return res;
}