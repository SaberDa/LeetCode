#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isPossibleDivide(vector<int>& nums, int k) {
    map<int, int> mp;
    for (auto x : nums) mp[x]++;
    for (auto x : mp) {
        if (x.second > 0) {
            for (int i = k - 1; i >= 0; i--) {
                mp[x.first + i] -= mp[x.first];
                if (mp[x.first + i] < 0) return false;
            }
        }
    }
    return true;
}