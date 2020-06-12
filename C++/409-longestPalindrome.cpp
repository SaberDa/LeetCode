#include <iostream>
#include <unordered_map>

using namespace std;

int longestPalindrome(string s) {
    if (s.empty()) return 0;
    unordered_map<char, int> mp;
    for (auto c : s) mp[c]++;
    int length = 0;
    for (auto it : mp) length += it.second / 2;
    return (length *= 2) < s.size() ? length + 1 : length;
}