#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {

    vector<int> nums;
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(73);
    nums.push_back(1);
    int k;

    k = 2;

    // Max heap
    unordered_map<int, int> temp;
    for (auto i : nums) {
        temp[i]++;
    }
    priority_queue<pair<int, int> > res;
    for (auto i : temp) {
        res.push({i.second, i.first});
    }
    vector<int> ans;
    while (k--) {
        ans.push_back(res.top().second);
        res.pop();
    }

    for (auto i : ans) {
        cout << i << endl;
    }



    return 0;
}

// bucket sort
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int>m;
//         for(auto x: nums) m[x]++;
//         vector<int>res;
//         vector<vector<int>>bucket(nums.size() + 1);
//         for(auto p: m) bucket[p.second].push_back(p.first);
//         for(int i = bucket.size() - 1; res.size() < k; i--)
//             for(auto j: bucket[i]) res.push_back(j);
//         return res;
//     }
// };