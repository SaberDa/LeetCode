#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

int singleNumber3(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}

int singleNumber(vector<int>& nums) {
    int x = 0;
    for (auto it : nums) {
        x ^= it;
    }
    return x;
}

int singleNumber1(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    unordered_map<int, int> mp;
    for (auto it : nums) {
        mp[it]++;
    }
    for (auto it : mp) {
        if (it.second == 1) {
            return it.first;
        }
    }
    return 0;
}