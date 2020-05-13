#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// solution 1 
// use unordered_map
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    if (nums1.empty() || nums2.empty()) {
        return res;
    }
    unordered_map<int, int> mp;
    for (auto i : nums1) {
        mp[i]++;
    }
    
    for (auto i : nums2) {
        if (mp[i] > 0) {
            res.push_back(i);
            mp[i] = 0;
        }
    }
    return res;
}

// solution 2
// use unordered_set
vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    if (nums1.empty() || nums2.empty()) {
        return res;
    }
    unordered_set<int> m(nums1.begin(), nums1.end());
    for (auto i : nums2) {
        if (m.count(i)) {
            res.push_back(i);
            m.erase(i);
        }
    }
    return res;
}

int main() {
    vector<int> nums1;
    // nums1.push_back(4);
    // nums1.push_back(9);
    // nums1.push_back(5);

    vector<int> nums2;
    nums2.push_back(9);
    nums2.push_back(4);
    nums2.push_back(9);
    nums2.push_back(8);
    nums2.push_back(4);

    vector<int> res = intersection(nums1, nums2);
    for (auto i: res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}