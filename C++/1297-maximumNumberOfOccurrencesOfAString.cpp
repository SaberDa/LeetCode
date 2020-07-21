#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    unordered_map<string, int> mp;
    for (int i = minSize; i <= minSize; i++) {
        for (int j = 0; j < s.size() - i + 1; j++) {
            mp[s.substr(j, i)]++;
        }
    }
    int res = 0;
    auto it = mp.begin();
    while (it != mp.end()) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < it->first.size(); i++) {
            cnt[it->first[i] - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] > 0) count++;
        }
        if (count <= maxLetters && it->second > res) {
            res = it->second;
        }
        it++;
    }
    return res;
}

