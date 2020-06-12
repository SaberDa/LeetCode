#include <iostream>
#include <unordered_map>

using namespace std;

char findTheDifference(string s, string t) {

    // unordered_map<char, int> mp;
    // for (auto c : s) mp[c]++;
    // for (auto c : t) mp[c]--;
    // for (auto it : mp) {
    //     if (it.second != 0) return it.first;
    // }
    // return NULL;

    char v = 0;
    for (auto c : s) v ^= c;
    for (auto c : t) v ^= c;
    return v;
}
