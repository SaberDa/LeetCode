#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersert(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    if (nums1.empty() || nums2.empty()) return res;
    unordered_map<int, int> mp;
    for (auto it : nums1) mp[it]++;
    for (auto it : nums2) {
        if (mp[it]) {
            mp[it]--;
            res.push_back(it);
        }
    }
    return res;
}