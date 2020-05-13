#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    int N = p.size();
    unordered_map<char, int> pmp;
    unordered_map<char, int> smp;
    
    for (int i = 0; i < N; i++) {
        pmp[p[i]]++;
        smp[s[i]]++;
    }
    if (pmp == smp) {
        res.push_back(0);
    }
    for (int i = N; i < s.size(); i++) {
        smp[s[i-N]]--;
        if (smp[s[i-N]] == 0) {
            smp.erase(s[i-N]);
        }
        smp[s[i]]++;
        if (smp == pmp) {
            res.push_back(i -N + 1);
        }
    }
    return res;
}