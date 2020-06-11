#include <iostream>
#include <unordered_map>

using namespace std;

bool canPermutePalindrome(string s) {
    if (s.empty()) return false;
    unordered_map<char, int> mp;
    int odd = 0;
    for (auto c : s) {
        (mp[c]++ % 2) ? odd-- : odd++;
    }
    return odd <= 1;
}