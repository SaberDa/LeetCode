#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isIsomorphic(string s, string t) {
    vector<int> mpS(256);
    vector<int> mpT(256);
    for (int i = 0, ns = 0, nt = 0; i < s.size(); i++) {
        if (!mpS[s[i]]) {
            mpS[s[i]] = ++ns;
        }
        if (!mpT[t[i]]) {
            mpT[t[i]] = nt++;
        }
        if (mpS[s[i]] != mpT[t[i]]) {
            return false;
        }
    }
    return true;
}