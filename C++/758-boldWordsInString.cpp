#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int calc(string s, int start, vector<string> &words) {
    int len = 0;
    for (auto w : words) {
        int size = w.size();
        if (start + size <= s.size() && s.substr(start, size) == w) {
            len = max(len, size);
        }
    }
    return len;
}

string boldWords(vector<string> &words, string S) {
    unordered_map<char, vector<string>> mp;
    for (auto s : words) {
        mp[s[0]].push_back(s);
    }
    for (int i = 0; i < S.size(); i++) {
        if (mp.count(S[i]) == 0) continue;
        int len = calc(S, i, mp[S[i]]);
        if (len == 0) continue;
        for (int j = i + 1; j <= i + len; j++) {
            int temp = calc(S, j, mp[S[j]]);
            len = max(len, j - i + temp);
        }
        S.insert(i + len, "</b>");
        S.insert(i, "<b>");
        i += len + 7;
    }
    return S;
}