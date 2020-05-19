#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstringDistinct(string s, int k) {
    int len = 0;
    unordered_map<char, int> mp;
    for (int l = 0, r = 0; r < s.size(); r++) {
        mp[s[r]]++;
        while (mp.size() > k) {
            mp[s[l]]--;
            if (mp[s[l]] == 0) {
                mp.erase(s[l]);
            }
            l++;
        }
        len = max(len, r - l + 1);
    }
    return len;
}

int main() {
    cout << lengthOfLongestSubstringDistinct("eceba", 2) << endl;
    return 0;
}

