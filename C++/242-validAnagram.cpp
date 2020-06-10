#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<int, int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i] - 'a']++;
        mp[t[i] - 'a']--;
    }
    for(auto it : mp) {
        if (it.second != 0) return false;
    }
    return true;

    // if (s.size() != t.size()) return false;
    // sort(s.begin(), s.end());
    // sort(t.begin(), t.end());
    // return s == t;
}