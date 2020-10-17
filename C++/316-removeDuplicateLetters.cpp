#include <vector>
#include <unordered_map>

using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> cnt(26);
    vector<bool> flag(26);
    string res = "";
    for (auto c : s) cnt[c - 'a']++;
    for (auto c : s) {
        cnt[c - 'a']--;
        if (flag[c - 'a']) continue;
        while (!res.empty() && res.back() > c && cnt[res.back() - 'a'] > 0) {
            flag[res.back() - 'a'] = false;
            res.pop_back();
        }
        flag[c - 'a'] = true;
        res.push_back(c);
    }
    return res;
}
