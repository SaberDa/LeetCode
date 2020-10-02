#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int minSteps(string s, string t) {
    vector<int> st(26, 0), tt(26, 0);
    for (int i = 0; i < s.size(); i++) {
        st[s[i] - 'a']++;
        tt[t[i] - 'a']++;
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (st[i] > tt[i]) {
            res += st[i] - tt[i];
        }
    }
    return res;
    // unordered_map<char, int> smp, tmp;
    // for (int i = 0; i < s.size(); i++) {
    //     smp[s[i]]++;
    //     tmp[t[i]]++;
    // }
    // int res = 0;
    // for (int i = 0; i < 26; i++) {
    //     if (smp[i + 'a'] > tmp[i + 'a']) {
    //         res = smp[i + 'a'] - tmp[i + 'a'];
    //     }
    // }
    // return res;
}