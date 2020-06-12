#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int res = 0;
    unordered_map<int, int> mp;
    for (auto i : A)
        for (auto j : B)
            mp[i + j]++;
    for (auto k : C) 
        for (auto l : D) {
            auto it = mp.find(0 - k - l);
            if (it != mp.end()) res += it->second;
        }
    return res;
}