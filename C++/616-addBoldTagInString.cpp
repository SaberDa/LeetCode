#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int calcLen(string &s, int start, vector<string> words) {
    int len = 0;
    for (auto w : words) {
        int size = w.size();
        if (start + size <= s.size() && s.substr(start, size) == w) {
            len = max(len, size);
        }
    }
    return len;
}

string addBoldTag(string s, vector<string> &dict) {
    unordered_map<char, vector<string>> mp;
    for (auto w : dict) {
        mp[w[0]].push_back(w);
    }
    for (int i = 0; i < s.size(); i++) {
        if (mp.count(s[i]) == 0) continue;
        int len = calcLen(s, i, mp[s[i]]);
        if (len == 0) continue;
        for (int j = i + 1; j <= i + len; j++) {
            int temp = calcLen(s, j, mp[s[j]]);
            len = max(len, j - i + temp);
        }
        s.insert(i + len, "</b>");
        s.insert(i, "<b>");
        i += len + 7;
    }
    return s;
}